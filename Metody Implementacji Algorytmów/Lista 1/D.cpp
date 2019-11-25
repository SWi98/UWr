#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

int main(){
    int N, K;/*
    cin >> N >> K;
    vector<int> cities(N);*/
    auto start = chrono::steady_clock::now();
    for(int i = 0; i < 1000000000; i++){
        long long int y = 91239132913;
        y = y / 2;
    }
    auto end = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << endl;
    auto start2 = chrono::steady_clock::now();
    for(int i = 0; i < 1000000000; i++){
        long long int z = 91239132913;
        z = z >> 1;
    }
    auto end2 = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << endl;
}