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
                cout << x << ", ";
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
                cout << x << ", ";
            }
        }
    }
};

void zad1_1(vector<double> vec, double lower, double upper){
    RangeVector one1(lower, upper);
    one1(vec);
}

void zad1_2(list<string> lstr, int lower, int upper){
    RangeList one2(lower, upper);
    one2(lstr);
}

void zad1_3(set<int> iset, int lower, int upper){
    [](set<int> _iset, int a, int b){
        for(const int &x : _iset){
            if (x >= a && x <= b){
                cout << x << ", ";
            }
        }
    }(iset, lower, upper);
}

void zad2_1(vector<double> vec, int p, int k){
    [](vector<double> _vec, int _p, int _k){
        for(_p; _p < _vec.size(); _p += _k){
            cout << _vec[_p] << ", ";
        }
    }(vec, p, k);
}

void zad2_2(list<string> lstr, int p, int k){
    [](list<string> _lstr, int _p, int _k){
        int i = 0; 
        for(list<string>::iterator iter = _lstr.begin(); iter != _lstr.end(); iter++){
            if(i >= _p && (i-_p) % _k == 0){
                cout << *iter << ", ";
            }
            i++;
        }
    }(lstr, p, k);
}

void zad2_3(set<int> iset, int p, int k){
    [](set<int> _iset, int _p, int _k){
        int i = 0; 
        for(const int &x : _iset){
            if(i >= _p && (i-_p) % _k == 0){
                cout << x << ", ";
            }
            i++;
        }
    }(iset, p, k);
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

pair<list<string>::iterator, list<string>::iterator> zad4_2(list<string> lstr){
    return [](list<string> _lstr){
        int minimal = numeric_limits<int>::max(); 
        int maximal = 0;
        list<string>::iterator smallest;
        list<string>::iterator biggest = _lstr.begin();
        for(list<string>::iterator iter = _lstr.begin(); iter != _lstr.end(); iter++){
            string current = * iter;
            if(current.size() < minimal){
                smallest = iter;
                minimal = current.size();
            }
            if(current.size() > maximal){
                biggest = iter;
                maximal = current.size();
            }
        }
        return pair<list<string>::iterator, list<string>::iterator>(smallest, biggest);
    }(lstr);
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
    cout << "a = 10; b = 40 (vector): "; zad1_1(vec, 10, 40);
    cout << "\na = 3; b = 10 (list): "; zad1_2(lstr, 3, 10);
    cout << "\na = 40; b = 98 (set): "; zad1_3(iset, 40, 98);
    cout << "\np = 3, k = 4 (vector): "; zad2_1(vec, 3, 4);
    cout << "\np = 2, k = 2 (list): "; zad2_2(lstr, 2, 2);
    cout << "\np = 3, k = 1 (set): "; zad2_3(iset, 3, 1);
    cout << "\naverage (vector): " << zad3_1(vec) << endl;
    cout << "average (set): " << zad3_3(iset) << endl;
    cout << "Min, max from vector: " << *zad4_1(vec).first << ", " << *zad4_1(vec).second << endl;
    pair<list<string>::iterator, list<string>::iterator> test = zad4_2(lstr);
    cout << "Min, max from list: " << *test.first << ", " << *test.second << endl;
    cout << "Min, max from set: " << *zad4_3(iset).first << ", " << *zad4_3(iset).second << endl;
    cout << "Sum of vector: " << zad5_1(vec) << endl;
    cout << "Sum of list: " << zad5_2(lstr) << endl;
    cout << "Sum of set: " << zad5_3(iset) << endl;
}