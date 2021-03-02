#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#include <tuple>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <random>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#define _boost ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;
using namespace chrono;

class Recipe{
    public:
    short int id, tier0, tier1, tier2, tier3, price;

    Recipe(short int id, short int t0, short int t1, short int t2, short int t3, short int price){
        this->id = id;
        this->tier0 = t0;
        this->tier1 = t1;
        this->tier2 = t2;
        this->tier3 = t3;
        this->price = price;
    }

    void Show(){
        cerr << id << " " << tier0 << " " << tier1 << " " << tier2 << " " << tier3 << " " << price << endl;
    }
};

class Spell{
    public:
    short int id, tier0, tier1, tier2, tier3, price;
    bool castable, repeatable;

    Spell(short int id, short int t0, short int t1, short int t2, short int t3, short int price, bool castable, bool repeatable){
        this->id = id;
        this->tier0 = t0;
        this->tier1 = t1;
        this->tier2 = t2;
        this->tier3 = t3;
        this->price = price;
        this->castable = castable;
        this->repeatable = repeatable;
    }

    void show(){
        cerr << id << " " << tier0 << " " << tier1 << " " << tier2 << " " << tier3 << " " << price << '\n';
    }
};

class Equipment{
    public:
    short int tier0, tier1, tier2, tier3;
};


enum Move{wait, cast, brew, rest, empty};

class Action{
    public:
    Move move;
    short int index;
    short int how_many;

    Action(){
        this->how_many = 0;
    }

    Action(Move m, short int index, short int how_many){
        this->move = m;
        this->index = index;
        this->how_many = how_many;
    }
};

class State{
    public:
    vector<Recipe> recipes;
    vector<Spell> spells;
    vector<Spell> learnableSpells; 
    Equipment eq; 
    Equipment enemyEq; 
    int score; 
    int enemyScore;
    Action previousMove; 
    State* previousState;

    State(){
        this->previousMove = Action(Move::empty, 0, 0);
        this->previousState = nullptr;
        score = 0;
        enemyScore = 0;
    }

    State(vector<Recipe> r, vector<Spell> s, Equipment myEq, Equipment enemyEq){
        this->recipes = r;
        this->spells = s;
        this->eq = myEq;
        this->enemyEq = enemyEq;
        this->previousMove = Action(Move::empty, 0, 0);
        this->previousState = nullptr;
        score = 0;
        enemyScore = 0;
    }

    State(vector<Recipe> r, vector<Spell> s, Equipment myEq, Equipment enemyEq, Action prevMove, State* prevState){
        this->recipes = r;
        this->spells = s;
        this->eq = myEq;
        this->enemyEq = enemyEq;
        this->previousMove = prevMove;
        this->previousState = prevState;
        score = 0;
        enemyScore = 0;
    }

    /**
     * @return Vector of states available after applying every castable spell and 'rest' action if at least one spell is not castable.
     **/
    vector<State*> getSuccessors(){
        vector<State*> successors;
        int castableCount = 0;
        for(short int i = 0; i < spells.size(); i++){
            if(spells[i].castable){
                castableCount++;
            }
            if(spells[i].repeatable){
                int repeats = 1;
                while(this->canCast(i, repeats)){
                    State *newState = new State(this->recipes, this->spells, this->eq, this->enemyEq, Action(Move::cast, i, repeats), this);
                    newState->spells[i].castable = false;
                    newState->eq.tier0 += spells[i].tier0 * repeats;
                    newState->eq.tier1 += spells[i].tier1 * repeats;
                    newState->eq.tier2 += spells[i].tier2 * repeats;
                    newState->eq.tier3 += spells[i].tier3 * repeats;
                    successors.push_back(newState);
                    repeats++;
                }
            }
            else if(this->canCast(i, 1)){
                State *newState = new State(this->recipes, this->spells, this->eq, this->enemyEq, Action(Move::cast, i, 0), this);
                newState->spells[i].castable = false;
                newState->eq.tier0 += spells[i].tier0;
                newState->eq.tier1 += spells[i].tier1;
                newState->eq.tier2 += spells[i].tier2;
                newState->eq.tier3 += spells[i].tier3;
                successors.push_back(newState);
            }
        }
        if(castableCount != spells.size()){
            State *newState = new State(this->recipes, this->spells, this->eq, this->enemyEq, Action(Move::rest, 0, 0), this);
            //refreshing the spells
            for(int i = 0; i < newState->spells.size(); i++){
                newState->spells[i].castable = true;
            }  
            successors.push_back(newState);
        }
        return successors; 
    }

    int bestRecipe(){
        short int bestIndex = -1;
        short int bestPrice = -1;
        for(int i = 0; i < recipes.size(); i++){
            if(recipes[i].price){
                bestPrice = recipes[i].price;
                bestIndex = i;
            }
        }
        return bestIndex;
    }

    int bestAvailableRecipe(){
        short int bestIndex = -1;
        short int bestPrice = -1;
        for(int i = 0; i < recipes.size(); i++){
            if(recipes[i].price > bestPrice && this->canBuy(i)){
                bestPrice = recipes[i].price;
                bestIndex = i;
            }
        }
        return bestIndex;
    }

    bool canBuy(short int recipeIndex){
        return eq.tier0 + recipes[recipeIndex].tier0 >= 0 && 
                eq.tier1 + recipes[recipeIndex].tier1 >= 0 && 
                eq.tier2 + recipes[recipeIndex].tier2 >= 0 && 
                eq.tier3 + recipes[recipeIndex].tier3 >= 0;
    }

    bool canCast(short int spellIndex, short int repeats){
            return spells[spellIndex].castable && 
            eq.tier0 + spells[spellIndex].tier0 * repeats >= 0 && 
            eq.tier1 + spells[spellIndex].tier1 * repeats >= 0 && 
            eq.tier2 + spells[spellIndex].tier2 * repeats >= 0 && 
            eq.tier3 + spells[spellIndex].tier3 * repeats >= 0 &&
            eq.tier0 + spells[spellIndex].tier0 * repeats + eq.tier1 + spells[spellIndex].tier1 * repeats + 
            eq.tier2 + spells[spellIndex].tier2 * repeats + eq.tier3 + spells[spellIndex].tier3 * repeats <= 10;
    }

    void cast(short int spellIndex){  
        eq.tier0 += spells[spellIndex].tier0;
        eq.tier1 += spells[spellIndex].tier1;
        eq.tier2 += spells[spellIndex].tier2;
        eq.tier3 += spells[spellIndex].tier3;
    }

    void show(){
        cerr << "EQ:" << eq.tier0 << " " << eq.tier1 << " " << eq.tier2 << " " << eq.tier3 << endl;
    }
};


std::chrono::high_resolution_clock::time_point t1;
bool FIRST_TURN;

class Game{
    public:
    State state;

    void doMove(){
        State* nextState = searchToNearest();
        cerr << "FOUND\n";
        if(nextState == nullptr){
            cerr << "TIMEOUT\n";
            for(int i = 0; i < this->state.spells.size(); i++){
                if(this->state.canCast(i, 1)){
                    cout << "CAST " << this->state.spells[i].id << endl;
                    return;
                }
            }
            cout << "REST" << endl;
        }
        else if(nextState->previousState == nullptr){
            int bestRecipeIndex = this->state.bestAvailableRecipe();
            if(bestRecipeIndex == -1){
                cerr << "Error: backpropagate returned current state and there's no available recipe\n";
            }
            cout << "BREW " << this->state.recipes[bestRecipeIndex].id << endl;
        }
        else{
            Action action = nextState->previousMove;
            switch(action.move){
                case Move::brew:
                cout << "BREW " << this->state.recipes[action.index].id << endl;
                break;
                case Move::cast:
                if(action.how_many > 1){
                    cout << "CAST " << this->state.spells[action.index].id << " " << action.how_many << endl;
                }
                else{
                    cout << "CAST " << this->state.spells[action.index].id << endl;
                }
                break;
                case Move::rest:
                cout << "REST" << endl;
                break;
                case Move::wait:
                cout << "WAIT" << endl;
                break;
                case Move::empty:
                cerr << "Error: doing empty move\n";
                cout << "WAIT" << endl;
                break;
            }
        }
        
        std::chrono::duration<double, std::milli> fp_ms = std::chrono::high_resolution_clock::now() - t1;
        cerr <<"inside doMove after BFS and write: " << fp_ms.count() << endl;
    }

    /**
     * BFS that finds the closest state that allows us to brew anything. 
     * @return Pointer to the first state from the route to the terminal state (excluding starting state - the current one).
     **/
    State* searchToNearest(){
        cerr << "BFS on\n";
        queue<State*> q;
        state.previousState = nullptr;
        q.push(&state);
        int counter = 0;
        t1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> fp_ms = std::chrono::high_resolution_clock::now() - t1;
        while(!q.empty()){
            State* currentState = q.front();
            q.pop();

            counter ++;

            // this condition is an artifact from the previous instance of the algorithm where BFS was bugged.
            // Currently It does nothing, It's just a safety measure in case my BFS would break for some reason. 
            if(counter%200== 0){
                fp_ms = std::chrono::high_resolution_clock::now() - t1;
                cerr << fp_ms.count() << endl;
                currentState->show();
                if(fp_ms.count() > 50 || (FIRST_TURN && fp_ms.count() > 1000)){
                    cerr << fp_ms.count() << endl;
                    cerr << "VISITED STATES: " << counter << endl;
                    return nullptr;
                }
            }

            int bestAvailPotionInd = currentState->bestAvailableRecipe();
            // if we can't create any potion from currentState
            if(bestAvailPotionInd == -1){
                vector<State*> neighbours = currentState->getSuccessors();
                for(int i = 0; i < neighbours.size(); i++){
                    neighbours[i]->previousState = currentState;
                    q.push(neighbours[i]);
                }
            }
            // if we are able to create a potion from currentState
            else{
                cerr << "VISITED STATES: " << counter << endl;
                return backpropagate(currentState);
            }
        }
        cerr << "Error: BFS found nothing\n";
        return nullptr;
    }

    /**
     * Traversing from the final state up to the first state after the one we are currently in. 
     **/
    State* backpropagate(State* finalState){
        int depth = 1;
        if(finalState->previousState == nullptr){
            cerr << "DEPTH: " << depth << endl;
            return finalState;
        }
        while(finalState->previousState->previousState != nullptr){
            depth++;
            finalState = finalState->previousState;
        }
        cerr << "DEPTH: " << depth << endl;
        return finalState;
    }
};

Game* GAME;

int main()
{   
    FIRST_TURN = true;
    srand(time(NULL));
    GAME = new Game();
    int counter = 0;
    // game loop
    while (1) {
        t1 = std::chrono::high_resolution_clock::now();
        GAME = new Game();
        int actionCount; // the number of spells and recipes in play
        cin >> actionCount; cin.ignore();
        for (int i = 0; i < actionCount; i++) {
            int actionId; // the unique ID of this spell or recipe
            string actionType; // in the first league: BREW; later: CAST, OPPONENT_CAST, LEARN, BREW
            int delta0; // tier-0 ingredient change
            int delta1; // tier-1 ingredient change
            int delta2; // tier-2 ingredient change
            int delta3; // tier-3 ingredient change
            int price; // the price in rupees if this is a potion
            int tomeIndex; // in the first two leagues: always 0; later: the index in the tome if this is a tome spell, equal to the read-ahead tax; For brews, this is the value of the current urgency bonus
            int taxCount; // in the first two leagues: always 0; later: the amount of taxed tier-0 ingredients you gain from learning this spell; For brews, this is how many times you can still gain an urgency bonus
            bool castable; // in the first league: always 0; later: 1 if this is a castable player spell
            bool repeatable; // for the first two leagues: always 0; later: 1 if this is a repeatable player spell
            cin >> actionId >> actionType >> delta0 >> delta1 >> delta2 >> delta3 >> price >> tomeIndex >> taxCount >> castable >> repeatable; cin.ignore();
            if(actionType == "BREW"){
                GAME->state.recipes.push_back(Recipe(actionId, delta0, delta1, delta2, delta3, price));
            }
            else if(actionType == "CAST"){
                GAME->state.spells.push_back(Spell(actionId, delta0, delta1, delta2, delta3, price, castable, repeatable));
            }
            else if(actionType == "LEARN"){
                GAME->state.learnableSpells.push_back(Spell(actionId, delta0, delta1, delta2, delta3, price, castable, repeatable));
            }
        }
        cin >> GAME->state.eq.tier0  >> GAME->state.eq.tier1  >> GAME->state.eq.tier2  >> GAME->state.eq.tier3  >> GAME->state.score; cin.ignore();
        cin >> GAME->state.enemyEq.tier0  >> GAME->state.enemyEq.tier1 >> GAME->state.enemyEq.tier2  >> GAME->state.enemyEq.tier3  >> GAME->state.enemyScore; cin.ignore();


        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        // in the first league: BREW <id> | WAIT; later: BREW <id> | CAST <id> [<times>] | LEARN <id> | REST | WAIT
        counter++;
        if(counter < 10){
            if(rand() % 10 < 1){
                cerr << "doMove() call\n";
                GAME->doMove();
            }
            else{
                cerr << "learn instead of move\n";
                cout << "LEARN " << GAME->state.learnableSpells[0].id << endl;
            }
        }
        else{
            GAME->doMove();
        }
        FIRST_TURN = false;
    }
}