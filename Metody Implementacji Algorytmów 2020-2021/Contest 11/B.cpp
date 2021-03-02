#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int big_calls;

long double newton_symbol(long long int a, long long int b, bool first_call)
{
    cout << a << " " << b << endl;
    long long int d1, d2;
    d1 = max(a - b, b);
    d2 = min(a - b, b);
    long double res = 1;
    int j = 2;
    int small_calls = 0;
    for (int i = d1 + 1; i <= a; i++)
    {
        res *= i;
        for(j; j <= d2; j++){
            res /= j;
        }
        if(res > 100){
            //cout << "BIIIIG\n";
            if(first_call){
                res /= 100;
                big_calls++;
            }
            else if(!first_call){
                res /= 100;
                small_calls++;
            }
        }
    }
    if(!first_call){
        for(int i = small_calls; i < big_calls; i++){
            //cout << "GOING DOWN BRO\n";
            res /= 100;
        }
    }
    return res;
}

long double sick_newton(long long int n, long long int k, long long int z){
    long double res = 1;
    long long int i = 1;
    //cout << n << " " << k << " " << z << endl;
    while(i <= max(n, z)){
        double coeff = 1;
        if(i <= n){
            //cout << "fst ";
            coeff *= i;
        }
        if(i <= z - k){
            //cout << "snd ";
            coeff *= i;
        }
        if(i <= n - k){
            //cout << "trd ";
            coeff /= i;
        }
        if(i <= z){
            //cout << "fourth ";
            coeff /= i;
        }
        //cout << endl;
        res *= coeff;
        i++;
    }
    return res;
}

int main()
{
    long long int others = 0, wafa;
    long long int n, m, h;
    cin >> n >> m >> h;
    for (long long int i = 1; i <= m; i++)
    {
        if (i == h)
        {
            cin >> wafa;
        }
        else
        {
            int new_team;
            cin >> new_team;
            others += new_team;
        }
    }
    wafa--;
    n--;
    if (others + wafa < n)
    {
        cout << -1;
    }
    else if(n > others){
        cout << 1.0;
    }
    else if(wafa == 0){
        cout << 0.0;
    }
    else
    {
        // cout <<"team: " << n << " others: " << others << " wafa: " << wafa << endl;
        // cout << newton_symbol(others, n) << endl;
        // // cout << newton_symbol(others + wafa, n) << endl;
        // big_calls = 0;
        // double x = newton_symbol(others, n, true);
        // double y = newton_symbol(others + wafa, n, false);
        cout << double(1.0 - sick_newton(others, n, others + wafa));
    }
    //     long double all_res = 0.0;
    //     long double res = 1.0;
    //    // cout << wafa << " " << others << " " << n << endl;
    //     for(int i = 1; i <= min(wafa, n); i++){
    //         res = 1.0;
    //         long long int current_wafa = wafa % n, current_others = others;
    //         //calculating the probability that i wafa members are in the team
    //         for(int j = 1; j <= i; j++){
    //             res *= double(current_wafa)/(current_wafa + current_others);
    //             current_wafa--;
    //         }
    //         //taking into account that we have to fill the team with the other students
    //         for(int j = i+1; j <= n; j++){
    //             res *= double(current_others)/(current_wafa + current_others);
    //             current_others--;
    //         }
    //         all_res += res;
    //         res = 1.0;
    //         current_wafa = wafa % n, current_others = others;
    //         for(int j = 1; j <= n-i; j++){
    //             res *= double(current_others)/(current_wafa + current_others);
    //             current_others--;
    //         }
    //         for(int j = n-i+1; j <= n; j++){
    //             res *= double(current_wafa)/(current_wafa + current_others);
    //             current_wafa--;
    //         }
    //         all_res += res;

    //     }   
    //     cout << all_res << endl;
    // }
}