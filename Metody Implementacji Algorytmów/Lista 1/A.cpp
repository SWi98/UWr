#include<iostream>
using namespace std;

int main(){
    int n;
    int l = 0;
    cin >> n;
    int * tab = new int[n];
    for(int i = 0; i < n; i++)
        cin >> tab[i];
    for(int i = 0; i < (n-1); i++){
        for(int j = (i+1); j < n; j++){
            if(tab[j] < tab[i]){
                l++;
            }
        }
    }
    cout << l;

}

