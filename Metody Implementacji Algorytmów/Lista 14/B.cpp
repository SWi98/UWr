#include <iostream>
using namespace std;

const long long int max_n = 1000000000;
int res;
long long int n;

bool good_number(long long int n){
    int digits[2] = {-1, -1};
    int digit;
    while(n > 0){
        digit = n % 10;
        n /= 10;
        if(digits[0] == - 1 || digits[0] == digit){
            digits[0] = digit;
        }
        else if(digits[1] == -1 || digits[1] == digit){
            digits[1] = digit;
        }
        else{
            return false;
        }
    }
    return true;
}

void DFS(long long int current){
    if(current <= n && current != 0){
        res++;
    }
    else if (current > n){
        return;
    }
    long long int new_number;
    for(int i = 0; i < 10; i++){               
        new_number = current * 10 + i;          // if 102 is a wrong number then there's no point in checking 1020, 1021, ... , 10200, 102001, ...
        if(good_number(new_number) && new_number != 0){
            DFS(new_number);
        }
    }
    
}

int main(){
    res = 0;
    cin >> n;
    DFS(0);
    cout << res << endl;
}