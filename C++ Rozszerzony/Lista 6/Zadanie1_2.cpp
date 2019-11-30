#include <iostream>
#include<algorithm>
#include <random>
#include <fstream>
#include <time.h>
using namespace std;

template <typename T>
void random_permutation(T tab[], int n){
    default_random_engine generator;
    generator.seed(time(NULL));
    for(int i = 0; i < n; i++){
        uniform_int_distribution<int> distribution(i, n-1);
        swap(tab[i], tab[distribution(generator)]);
    }
}

void uniform(){
    default_random_engine generator;
    generator.seed(time(NULL));
    uniform_real_distribution<float> distr; 
    ofstream myfile;
    myfile.open("uniform.csv");
    for(int i = 0; i < 1000; i++){
        myfile << distr(generator) << "\n";
    }
    myfile.close();
}

void binomial(){
    default_random_engine generator;
    generator.seed(time(NULL));
    binomial_distribution<int> distr(100, (double)0.5);  // The value obtained is the number of successes in a sequence of t yes/no experiments, each of which succeeds with probability p.
    ofstream myfile;
    myfile.open("binomial.csv");
    for(int i = 0; i < 1000; i++){
        myfile << distr(generator) << "\n";
    }
    myfile.close();
}

void normal(){
    default_random_engine generator;
    generator.seed(time(NULL));
    normal_distribution<double> distr;
    ofstream myfile;
    myfile.open("normal.csv");
    for(int i = 0; i < 1000; i++){
        myfile << distr(generator) << "\n";
    }
    myfile.close();
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
    
    for(int i = 0; i < 20; i++){
        cout << tab[i] << endl;
    }
}