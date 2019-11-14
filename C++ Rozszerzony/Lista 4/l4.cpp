#include <iostream>
#include <vector>
#include <time.h>
#include <list>
#include <set>
#include <numeric>
#include <limits>
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

double zad3_1(vector<double> vec){
    return [](vector<double> _vec){
        return accumulate(_vec.begin(), _vec.end(), 0.0) / _vec.size();
    }(vec);
}

int zad3_3(set<int> iset){
    return [](set<int> _iset){
        return accumulate(_iset.begin(), _iset.end(), 0.0) / _iset.size();
    }(iset);
}

pair<vector<double>::iterator, vector<double>::iterator> zad4_1(vector<double> vec){
    return [](vector<double> _vec){
        double minimal = numeric_limits<double>::max(); 
        double maximal = numeric_limits<double>::min();
        vector<double>::iterator smallest;
        vector<double>::iterator biggest; 
        for(vector<double>::iterator iter = _vec.begin(); iter != _vec.end(); iter++){
            if(*iter < minimal){
                smallest = iter;
                minimal = *iter;
            }
            
            if(*iter > maximal){
                biggest = iter;
                maximal = *iter;
            }
        }
        return pair<vector<double>::iterator, vector<double>::iterator>(smallest, biggest);
    }(vec);
}

pair<set<int>::iterator, set<int>::iterator> zad4_3(set<int> iset){
    return [](set<int> _iset){
        int minimal = numeric_limits<int>::max();
        int maximal = numeric_limits<int>::min();
        set<int>::iterator smallest;
        set<int>::iterator biggest;
        for(set<int>::iterator iter = _iset.begin(); iter != _iset.end(); iter++){
            if(*iter < minimal){
                smallest = iter;
                minimal = *iter;
            }
            
            if(*iter > maximal){
                biggest = iter;
                maximal = *iter;
            }
        }
        return pair<set<int>::iterator, set<int>::iterator>(smallest, biggest);
    }(iset);
}

double zad5_1(vector<double> vec){
    return [](vector<double> _vec){
        return accumulate(_vec.begin(), _vec.end(), 0.0);
    }(vec);
}

string zad5_2(list<string> lstr){
    return [](list<string> _lstr){
        return accumulate(_lstr.begin(), _lstr.end(), string(""));
    }(lstr);
}
int zad5_3(set<int> iset){
    return [](set<int> _iset){
        return accumulate(_iset.begin(), _iset.end(), 0.0);
    }(iset);
}


int main(){
    srand(time(NULL));

    vector<double> vec;
    cout << "VECTOR:" << endl;
    for(int _ = 0; _ < 12; _++){
        double x = (rand() / double(RAND_MAX)) * 100;
        cout << x << endl;
        vec.push_back(x);
    }

    list<string> lstr;
    cout << "\nLIST:" << endl;
    for(int _ = 0; _ < 12; _++){
        string x;
        for(int _ = 0; _ < rand()%20 + 1; _++){
            x.push_back(chars[rand() % sizeof(chars) -1]);
        }
        cout << x << endl;
        lstr.push_back(x);
    }

    set<int> iset; 
    cout <<"\nSET:" << endl;
    for(int _ = 0; _ < 12; _++){
        int x = rand() % 100 + 1;
        cout << x << endl;
        iset.insert(x);
    }
    cout << "------------------------------------------\n";
    cout << "Min, max from vector: " << *zad4_1(vec).first << ", " << *zad4_1(vec).second << endl;
    cout << "Min, max from set: " << *zad4_3(iset).first << ", " << *zad4_3(iset).second << endl;
    cout << "Sum of vector: " << zad5_1(vec) << endl;
    cout << "Sum of list: " << zad5_2(lstr) << endl;
    cout << "Sum of set: " << zad5_3(iset) << endl;
}