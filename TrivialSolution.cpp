//
// Created by Fidelia Nawar on 5/4/20.
//

#include "TrivialSolution.h"
#include <iostream>

using std::cout;

bool TrivialSolution::isValid(int row, int column, vector<int> &queens) {
    for(int i=0; i<row; i++){
        if(queens[i] == column){
            return false;
        }
        if(queens[i]-column == i-row){
            return false;
        }
        if(queens[i]-column == row-i){
            return false;
        }
    }
    return true;
}

void TrivialSolution::helper(int row, vector<int> &q, vector<vector<string> > &result) {
    if(row == N){
        vector<string> tempVec(N, string(N, '0'));
        for(int i=0; i<N; i++) {
            tempVec[i][q[i]] = '1';
        }
        result.push_back(tempVec);
    } else {
        for(int i=0; i<N; i++) {
            if(isValid(row, i, q)){
                q[row] = i;
                helper(row+1, q, result);
            }
        }
    }
}

vector<vector<string>> TrivialSolution::solveNQueens(int n) {
    N = n;
    vector<vector<string>> ret;
    vector<int> q(N, 0);
    helper(0, q, ret);
    for(int i = 0; i < ret.size(); i++){
        for(int j = 0; j < ret[i].size(); j++) {
            if((j/N)==0){
                cout << endl;
            }
            for(char c : ret[i][j]){
                std::cout << " " << c <<" ";
            }
        }
        cout << endl;
    }
    return ret;
}