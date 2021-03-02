#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <tuple>
using namespace std;

int convertDate(int month, int day){
    //cout << "month: " << month << " day: " << day << endl;
    int sum = 0;
    if(month > 1){
        sum += 31;
    }
    if(month > 2){
        sum += 28;
    }
    for(int i = 3; i < month; i++){
        if(i <= 7){
            if(i % 2 == 0){
                sum += 30;
            }
            else{
                sum += 31;
            }
        }
        else{
            if(i % 2 == 0){
                sum += 31;
            }
            else{
                sum += 30;
            }
        }
    }
    sum += day;
    return sum;
}

int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

pair<int, int> convertNumber(int date){
    int m;
    for(m = 0; m < 12 && date >= months[m]; m++){
        date -= months[m];
    }
    if(m == 0 && date == 0){
        return {12, 31};
    }
    if(date == 0){
        return {m, months[m-1]};
    }
    return {m+1, date};
}

int main(){
    // 10 - 27 == 300
    int n;
    cin >> n;
    vector<string> dates(n);
    vector<int> number(n);
    string a;
    for(int i = 0; i < n; i++){
        cin >> a >> dates[i];
        string month = dates[i].substr(0, 2);
        string day = dates[i].substr(3, 3);
        if(month[0] == '0'){
            month = month.substr(1, 1);
        }
        if(day[0] == '0'){
            day = day.substr(1, 1);
        }
        //cout << month << " " << day << endl;
        number[i] = convertDate(stoi(month), stoi(day));
        //cout << number[i] << endl;
    }
    // for(int i = 0; i < n; i++){
    //     cout << dates[i] << " == " << number[i] << endl;
    // }
    sort(number.begin(), number.end());
    int max_diff, best_date;
    if(!(number[n-1] == 365 && number[0] == 1)){
        max_diff = abs(number[0] + (365 -  number[n-1]));
        best_date = number[0] - 1;
    }
    else{
        max_diff = -1;
        best_date = number[0] - 1;
    }
    for(int i = 0; i < n; i++){
        int curr = number[i] - number[i-1];
        if(number [i] - 1 != number[i-1]){
            if(curr > max_diff){
                max_diff = curr;
                best_date = number[i] - 1;
            }
            else if(curr == max_diff){
                if(best_date <= 300 && (number[i] - 1) > 300){
                    best_date = number[i] - 1;
                }
            }
        }
    }
   // cout << best_date << endl;
    pair<int, int> res = convertNumber(best_date);
    if(res.first < 10){
        cout << "0";
    }
    cout << res.first << "-";
    if(res.second < 10){
        cout << "0";
    }
    cout << res.second;
}