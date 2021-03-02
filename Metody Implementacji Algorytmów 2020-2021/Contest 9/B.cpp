#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
int a, b, k;
vector<bool> is_prime;
vector<long long int> prime_sum;
bool found;
 
bool good(int l){
    //return l > 7;
    int count = 0;
   // cout << "_______________________\n";
 //   cout << "l: " << l << endl;
  //  cout << "a: " << a << " b: " << b << endl;
    for(int x = a; x <= b - l + 1; x++){
        // int count = 0;
       // cout << "x: " << x << " prime sum: " << prime_sum[x+l-1] << " " << prime_sum[x] << endl;
        // for(int x_ = x; x_ <= x + l - 1; x_++){
        //      //cout << "x_: " << x_ << " " << is_prime[x_] << ";  ";
        //     count += is_prime[x_];
        // }
        if(prime_sum[x] - prime_sum[x+l-1]  + is_prime[x+l-1]< k){
       //     cout << "____________false___________\n";
            return false;
        }
       // cout << endl;
        // if(count < k){
        //     //cout << "_______________________\n";
        //     return false;
        // }
    }
  //  cout << "___________true____________\n";
    return true;
}
 
int binSearch(int l, int r){
    while(true){
        if(l == r){
            if(good(l)){
                return l;
            }
            else{
                return -1;
            }
        }
        int m = (l+r)/2;
        //cout << l << " " << r << " " << m << endl;
        bool is_good = good(m);
        if(is_good){
            r = m;
        }
        else{
            l = m+1;
        }
 
    }
    // if(l == r){
    //     if(good(l)){
    //         return l;
    //     }
    //     else{
    //         return -1;
    //     }
    // }
    // int m = (l+r)/2;
    // //cout << l << " " << r << " " << m << endl;
    // bool is_good = good(m);
    // if(is_good){
    //     return binSearch(l, m);
    // }
    // else{
    //     return binSearch(m+1, r);
    // }
}
 
int main(){   
    cin >> a >> b >> k;
    is_prime.resize(b+1, true);
    prime_sum.resize(b+1, 0);
    is_prime[1] = false;
    for(int i = 2; i <= sqrt(b); i++){
        if(is_prime[i]){
            for(int j = i*i; j <= b; j += i){
                is_prime[j] = false;
            }
        }
    }
    prime_sum[b] = is_prime[b];
    for(int i = b-1; i >= 0; i--){
        prime_sum[i] = is_prime[i] + prime_sum[i+1];
    }
    // for(int i = 1; i <= b; i++){
    //     cout << prime_sum[i] << " ";
    // }
    // return 0;
    cout << binSearch(1, b-a+1);
    // bool found = true;
    // for(int l = 1; l <= b-a+1; l++){
    //     int count = 0;
    //     found = true;
    //     //cout << "l: " << l << endl;
    //     for(int x = a; x <= b - l + 1; x++){
    //         int count = 0;
    //         //cout << "x: " << x << endl;
    //         for(int x_ = x; x_ <= x + l - 1; x_++){
    //            // cout << "x_: " << x_ << " " << is_prime[x_] << ";  ";
    //             count += is_prime[x_];
    //         }
    //         //cout << endl;
    //         if(count < k){
    //             found = false;
    //             break;
    //         }
    //     }
    //     if(found){
    //         cout << l << endl;
    //         return 0;
    //     }
    // }
    // cout << -1 << endl;
}