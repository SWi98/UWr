#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> prices(n+1);
    vector<vector<int>> nOBaloons(n+1, vector<int>(3, 0));
    long long int price;
    string baloons;
    long long int min_price = 999999999;
    int cheapest_pack = 0;
    int zeros, ones, twos;
    for(int i = 1; i <= n; i++){
        cin >> price;
        cin >> baloons;
        zeros = ones = twos = 0;
        for(int j = 0; j < baloons.size(); j++){
            if(baloons[j] == '0'){
                zeros++;
            }
            else if(baloons[j] == '1'){
                ones++;

            }
            else if(baloons[j] == '2'){
                twos++;
            }
        }
        if(zeros > 0 && ones > 0 && twos > 1 && min_price > price){
            cheapest_pack = i;
            min_price = price;
        }
    }
    cout << cheapest_pack;

}