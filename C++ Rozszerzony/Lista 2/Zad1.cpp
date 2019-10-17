#include <iostream>
#include <memory>
#include<vector>
#include <math.h>
#include <cstdlib>
using namespace std;

int SIZE = 10000; 
vector<int> primes = vector<int>();

class counter{
    public:
    uint64_t get_value(){
        return val;
    }
    
    void set_value(uint64_t x){
        val = x;
    }

    counter(){
        val = 1;
    }

    private:
    uint64_t val;
};

void find_primes(){
    bool tab[SIZE];

    for(int i = 2; i < SIZE; i++)
        tab[i] = true;

    for(int i = 2; i < sqrt(SIZE); i++){
        if (tab[i]){
            for(int j = i * i; j < SIZE; j = j + i)
                tab[j] = false;
        }
    }
    
    for(int i = 2; i < SIZE; i++){
        if (tab[i])
            primes.push_back(i);
    }
}

void multiply_random(unique_ptr<counter[]> &tab, int n, int m, int i){
    int random = rand() % (n-1) + n; 
    int random_pos;
    bool used[n];

    for(int j = 0; j < n; j++)
        used[j] = false;

    for(int j = 0; j < random; j++){
        random_pos = rand() % (n-1);
        if (!used[random_pos]){
            uint64_t current_value = tab[random_pos].get_value();
            tab[random_pos].set_value(current_value * primes[j]); 
            used[random_pos] = true;
        }
    }
    
    if(i < m)
        multiply_random(tab, n, m, i+1);
}

int main(){
    srand(time(NULL));
    find_primes();
    int n;
    cin >> n;
    //unique_ptr<counter[]> tab(new counter[n]);
    unique_ptr<counter[]> tab = make_unique<counter[]>(n);
    multiply_random(tab, n, 1, 1);

    cout << "________________" << endl;

    for(int i = 0; i < n; i++){
        cout << tab[i].get_value() << endl;
    }
}