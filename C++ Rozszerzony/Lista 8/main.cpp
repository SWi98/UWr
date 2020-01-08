#include <iostream>
#include <regex>

using namespace std;

bool match(string exp, regex reg){
    return regex_match(exp, reg);
}

regex time(string exp){
    regex match("^([0-1][0-9]|2[0-3]):([0-5][0-9])(:[0-5][0-9])?$");
    return match;
}
 
regex date(string exp){
    regex match("^(((3[0-1]|[0-2][0-9])-(0[13579]|11))|((30|[0-2][0-9])-(0[468]|10|12))|([0-1][0-9]|2[0-8])-02)-[0-9][0-9][0-9][0-9]$");
    return match;
}

regex town(string str)
{
    regex match("^(([A-Z][a-z]{2,})(([ ]+[A-Z][a-z]{2,})*)?)|([A-Z][a-z]{2,}([-][A-Z][a-z]{2,})?)$");
    return match;
}

regex complex(string expr){
    regex match("^[(][ ]*[+-]?[0-9]+([.][0-9]*)?[ ]*([+]|[-])[ ]*[0-9]+([.][0-9]*)?[i][ ]*[)]$");
    return match;
}

int main(){
    string tests1[10] = {"19:19","24:14","23:19:19","00:01:01","000:00","BB:BB:CC","AA:11","12:00","14:59:59","23:60:60"};
    for(string x : tests1){
        cout << x << "  wynik - " << match(x, time(x)) << endl;
    }
    cout << endl;
    string tests2[10] = {"31-11-1999","31-12-1999","28-02-2014","28-01-0011","30-02-2000","19-19-20000","32-12-0000","aa:bb:cccc","01-01-0567","31-07-1998"};
    for(string x : tests2){
        cout << x << "  wynik - " << match(x, date(x)) << endl;
    }
    cout << endl;
    string tests3[5] = {"Czechowice-Dziedzice", "Czechowice Dziedzice Dziedzice", "Czechowice dziedzice", 
                "Czechowice-Dziedzice-Dziedzice", "czechowice-dziedzice"};
    for(string x : tests3){
        cout << "\"" + x << "\"  wynik - " << match(x, town(x)) << endl;
    }
    cout << endl;
    string tests4[7] = {"(       1.1 + 1.1i)","(-2.999990 -99999i)","(a + i)","(0 + i)","(0.0 + Xi)",
                "( -123450    -     1234.99999i)", "(1 + 2)"};
    for(string x : tests4){
        cout << x << "  wynik - " << match(x, complex(x)) << endl;
    }
}