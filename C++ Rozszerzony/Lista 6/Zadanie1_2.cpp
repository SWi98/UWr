#include <iostream>
#include<algorithm>
#include <random>
#include <fstream>
using namespace std;

template <typename T>
void random_permutation(T tab[], int n){
    default_random_engine generator;
    uniform_int_distribution<int> distribution(0, n-1);
    for(int i = 0; i < n; i++){
        swap(tab[i], tab[distribution(generator)]);
    }
}

/*template<typename T>
void random_permutation_range(T first, T last){
    int how_many = last - first;
    default_random_engine generator;
    uniform_int_distribution<int> distribution(0, how_many-1);
    for(int i = 0; i < how_many; i++){
        //swap(first[i], ++first[distribution(generator)]);
        cout << first[i] << endl;
    }
}*/

void uniform(){
    default_random_engine generator;
    uniform_real_distribution<float> distr; 
    ofstream myfile;
    myfile.open("uniform.csv");
    for(int i = 0; i < 1000; i++){
        myfile << distr(generator) << "\n";
    }
}

void binomial(){
    default_random_engine generator;
    binomial_distribution<int> distr(100, (double)0.5);  // The value obtained is the number of successes in a sequence of t yes/no experiments, each of which succeeds with probability p.
    ofstream myfile;
    myfile.open("binomial.csv");
    for(int i = 0; i < 1000; i++){
        myfile << distr(generator) << "\n";
    }
}

void normal(){
    default_random_engine generator;
    normal_distribution<double> distr;
    ofstream myfile;
    myfile.open("normal.csv");
    for(int i = 0; i < 1000; i++){
        myfile << distr(generator) << "\n";
    }
}

int main(){
    int tab[20];
    for(int i = 0; i < 20; i++){
        tab[i] = i;
    }
    random_permutation(tab, 20);
    uniform();
    binomial();
    normal();
    /*
    default_random_engine generator;
    uniform_int_distribution<int> distribution(0, 14);
    for(int i = 0; i < 15; i++){
        cout << distribution(generator) << endl;
    }*/
}