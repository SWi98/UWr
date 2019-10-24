#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

void fill_vector(vector<vector<double>> &matrix){
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            double random = (rand() % 16 + 5) / 10;
            matrix[i][j] = random;
        }
    }
}

vector<vector<double>> mult(vector<vector<double>> &matrix){
    int N = matrix.size();
    vector<vector<double>> new_matrix(N, vector<double>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            new_matrix[i][j] = 0;
            for(int k = 0; k < N; k++){
                new_matrix[i][j] += matrix[i][k] * matrix[k][j];
            }
        }
    }
    return new_matrix; 
}

int main(){
    srand(time(NULL));
    vector<vector<double>> matrix10(10, vector<double>(10));
    vector<vector<double>> matrix100(100, vector<double>(100));
    vector<vector<double>> matrix1000(1000, vector<double>(1000));
    vector<vector<double>> matrix10000(10000, vector<double>(10000));
    fill_vector(matrix10); fill_vector(matrix100); fill_vector(matrix1000); fill_vector(matrix10000);

    chrono::duration<double> sum(0);
    for(int i = 0; i < 10; i++){
        auto start = chrono::high_resolution_clock::now();
        matrix100 = mult(matrix100);
        auto end = chrono::high_resolution_clock::now();
        sum += chrono::duration_cast<chrono::duration<double>>(end - start);
    }
    cout << sum.count() / 10 << endl;
}