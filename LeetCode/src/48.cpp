#include<vector>
#include<iostream>

using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for(int i = 0; i< n; i++){
        for(int j = 0; j<i ; j++){
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    for(int j = 0, k = n -1 ; j<k; j++, k--){
        for(int i = 0; i<n ; i++){
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][k];
            matrix[i][k] = temp;
        }
    }
    
}