#include <iostream>
#include <vector>
#include <math.h> 
using namespace std;

int main(){
    int sought_flat, input_size; 
    cin >> sought_flat >> input_size; 
    vector<vector<int>> floors(101);
    int dividers_of_100[9] = {1, 2, 4, 5, 10, 20, 25, 50, 100};
    int flat, floor;
    for(int i = 0; i < input_size; i++){
        cin >> flat >> floor;
        floors[floor].push_back(flat);
    }
    int count = 0;
    int flat_number = -1;
    bool possible;
    int ans = -1;
    int new_ans = -2;
    for(int i = 1; i <= 100; i++){
        possible = true;
        for(int j = 1; j < floors.size(); j++){
            int range_start = (j - 1) * i  + 1;
            int range_end = j * i;
            //cout << "Case " << i << ". Range: [ " << range_start << " ; " << range_end << " ]" << endl;
            for(int k = 0; k < floors[j].size(); k++){
                if(floors[j][k] < range_start || floors[j][k] > range_end){
                    possible = false;
                    break;
                }
            }
            if (!possible){
                break;
            }
        }
        if(possible){
            count ++;
            flat_number = i;
            new_ans = ceil((double)sought_flat / flat_number);
            if(count == 1){
                ans = new_ans;
            }
            else{
                if(ans != new_ans){
                    cout << - 1;
                    return 0;
                }
            }
        }
    }
    cout << ans;
}