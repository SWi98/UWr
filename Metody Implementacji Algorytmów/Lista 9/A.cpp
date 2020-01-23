#include<iostream>
using namespace std;
int main(){
    string word;
    cin >> word;
    int odd_letters = 0;
    int number_of_letters[26];
    fill(begin(number_of_letters), end(number_of_letters), 0);
    for(int i = 0; i < word.length(); i++){
        number_of_letters[word[i] - 'a']++;
    }
    for(int i = 0; i < 26; i++){
        if(number_of_letters[i] % 2 != 0){
            odd_letters++;
        }
    }
    if(odd_letters <= 1 || odd_letters % 2 != 0){
        cout << "First";
    }
    else{
        cout << "Second";
    }
}