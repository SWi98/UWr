#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int N;
int n, m, n2;
vector<int>series;
void fill(){

}

void print(){
    int first_vertice = n2;
    int last_vertice = (N-1);
    for(int j = 0; j < n; j++){
        for(int i = first_vertice; i <= last_vertice; i++){
             cout << i  << " = " << series[i] << ";  ";
        }
        first_vertice /= 2;
        last_vertice /= 2;
        cout << endl;
    }
    cout << " 1 = " << series[1] << endl;
}

int main(){
    cin >> n >> m;
    N = pow(2, n+1);
    n2 = pow(2, n);
    series.resize(N, 0);
    //cout << "n = " << n << "; m = " << m << "; N = " << N << "; n2 = " << n2 << endl;
    for(int i = n2; i < N; i++){
        cin >> series[i];
    }
    int first_vertice = n2 / 2;
    int last_vertice = (N-1) / 2;
    bool calculate_or = true;
    for(int j = 0; j < n; j++){
        for(int i = first_vertice; i <= last_vertice; i++){
             //cout << i << " ";
             if(calculate_or){      // a_2i or a_(2i + 1)
                 series[i] = series[2 * i] | series[2 * i + 1];
             }
             else{                  // a_2i xor a_(2i + 1)
                series[i] = series[2 * i] ^ series[2 * i + 1];
             }
        }
        if(calculate_or){
            calculate_or = false;
        }
        else{
            calculate_or = true;
        }
        first_vertice /= 2;
        last_vertice /= 2;
        //cout << endl;
    }
    int pos, new_val;
    int second_pos;
    //cout << series[1];
    while(m--){
        cin >> pos >> new_val;
        pos = pos + n2 - 1;
        calculate_or = true;
        for(int j = 0; j <= n; j++){
            series[pos] = new_val;
            //cout << j << ". pos = " << pos << endl;
            if(pos == 1){
                cout << series[1] << endl;
                break;
            }
            if(pos % 2 == 0){
                second_pos = pos + 1;
            }
            else{
                second_pos = pos - 1;
            }
            if(calculate_or){
                new_val = series[pos] | series[second_pos];
                calculate_or = false;
            }
            else{
                new_val = series[pos] ^ series[second_pos];
                calculate_or = true;
            }
            pos /= 2;
        }
        //print();
    }
}