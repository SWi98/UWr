#include <iostream>
#include <string>
#include <stack>
#include <list>
#include <queue>
using namespace std;

bool is_op_or_par(char x){
     return (x == '(' || x == ')' || x =='+' || x == '-' || x == '/' || x == '*');
}

bool is_digit(char x){
    return x >= '0' && x <= '9';
}

list<string> split(string &tosplit){
    list<string> exprs; 
    string number = "";

    for(int i = 0; i < tosplit.size(); i++){
        string char_to_push(1, tosplit[i]);

        if(is_digit(tosplit[i])){               //If current char is a digit, we append it to the number being currently created.
            number += tosplit[i];
        }
        else if(is_op_or_par(tosplit[i])){      //If char is operator or parenthesis, 
            if(number.length() > 0){            //we add to the list the number entered before this char, and then the char. 
                exprs.push_back(number);
                number = "";
            }
            exprs.push_back(char_to_push);
        }
    }

    if(number.length() > 0){
        exprs.push_back(number);
        number = "";
    }
    return exprs;
}

void toONP(string expression){
    queue<string> out; 
    stack<string> st; 
    list<string> exprs = split(expression);
    
    for(string current : exprs){
        if(current.length() == 1){
            if(isdigit(current[0])){
                out.push(current);
            }
            else if(current == "("){
                st.push(current);
            }
            else if(current == ")"){
                string from_top = st.top();
                st.pop();
                while(from_top != "("){
                    out.push(from_top);
                    from_top = st.top();
                    st.pop();
                }
            }
            else if(current == "+" || current == "-"){
                while(!st.empty() && (st.top() == "+" ||st.top() == "-" || st.top() == "*" ||st.top() == "/")){
                    out.push(st.top());
                    st.pop();
                }
                st.push(current);
            }
            else{
                st.push(current);
            }
        }
        else{
            out.push(current);
        }
    }

    while(st.size() > 0){
        out.push(st.top());
        st.pop();
    }
    
    int queue_size = out.size();
    for(int i = 0; i < queue_size; i++){
        cout << out.front() << " ";
        out.pop();
    }
}

int main(){
    string expression;
    getline(cin, expression);
    toONP(expression);
}