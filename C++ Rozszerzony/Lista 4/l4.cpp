#include <iostream>
#include <vector>
#include <time.h>
#include <list>
#include <set>
#include <numeric>
using namespace std;

static const char chars[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

class RangeVector{
    private:
    double a, b;

    public:
    RangeVector(double a, double b){
        this->a = a;
        this->b = b; 
    }
    void operator()(vector<double> vec){
        for(const double &x : vec){
            if (x <= b && x >= a){
                cout << x << endl;
            }
        }
    }
};

class RangeList{
    private:
    int a, b;

    public:
    RangeList(int a, int b){
        this->a = a;
        this->b = b;
    }
    void operator()(list<string> lstr){
        for(const string &x : lstr){
            if(x.size() <= b && x.size() >= a){
                cout << x << endl;
            }
        }
    }
};

void zad1_1(vector<double> vec){
    RangeVector one1(10, 50);
    one1(vec);
}

void zad1_2(list<string> lstr){
    RangeList one2(5, 12);
    one2(lstr);
}

void zad1_3(set<int> iset){
    [](set<int> _iset, int a, int b){
        for(const int &x : _iset){
            if (x >= a && x <= b){
                cout << x << endl;
            }
        }
    }(iset, 45, 78);
}

void zad2_1(vector<double> vec){
    [](vector<double> _vec, int p, int k){
        for(p; p < _vec.size(); p += k){
            cout << _vec[p] << endl;
        }
    }(vec, 9, 2);
}

void zad2_2(list<string> lstr){
    [](list<string> _lstr, int p, int k){
        int i = 0; 
        for(list<string>::iterator iter = _lstr.begin(); iter != _lstr.end(); iter++){
            if(i >= p && (i-p) % k == 0){
                cout << i << " " << *iter << endl;
            }
            i++;
        }
    }(lstr, 2, 2);
}

void zad2_3(set<int> iset){
    [](set<int> _iset, int p, int k){
        int i = 0; 
        for(const int &x : _iset){
            if(i >= p && (i-p) % k == 0){
                cout << i << " " << x << endl;
            }
            i++;
        }
    }(iset, 3, 3);
}

void zad3_1(vector<double> vec){
    [](vector<double> _vec){
        cout << accumulate(_vec.begin(), _vec.end(), 0.0) / _vec.size();
    }(vec);
}

void zad3_3(set<int> iset){
    [](set<int> _iset){
        cout << accumulate(_iset.begin(), _iset.end(), 0.0) / _iset.size();
    }(iset);
}

int main(){
    srand(time(NULL));

    vector<double> vec;
    for(int _ = 0; _ < 12; _++){
        double x = (rand() / double(RAND_MAX)) * 100;
        vec.push_back(x);
    }

    list<string> lstr;
    for(int _ = 0; _ < 12; _++){
        string x;
        for(int _ = 0; _ < rand()%20 + 1; _++){
            x.push_back(chars[rand() % sizeof(chars) -1]);
        }
        lstr.push_back(x);
    }

    set<int> iset; 
    for(int _ = 0; _ < 12; _++){
        iset.insert(rand() % 100 + 1);
    }

}