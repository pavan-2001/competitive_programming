#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

const int n = 9;

int count_answers = 0;

bool isSafe(int matrix[9][9], int row , int col, int num) {
    // checking for row 
    for(int i=0;i<9;i++) {
        if(matrix[row][i] == num)
        return false;
    }
    // checking for column
    for(int i=0;i<9;i++) {
        if(matrix[i][col] == num)
        return false;
    }
    // 

    for(int i=3*((int)(row/3)) ; i<(((int)(row/3))+3); i++) {
        for(int j=3*((int)(col/3)); j<(((int) (col/3))+3); j++) {
            if(matrix[i][j] == num)
            return false;
        }
    }

    return true;

}


bool solve(int matrix[9][9]) {
   for(int i=0;i<n;i++) {
       for(int j=0;j<n;j++) {
           if(matrix[i][j] == 0) {
               for(int num = 1; num < 10;num++) {
                   if(isSafe(matrix, i, j, num)) {
                       matrix[i][j] = num;
                       if(solve(matrix))
                       return true;
                       matrix[i][j] = 0;
                   }
               }
               return false;
           }
       }
   }
    return true;
}

bool isItSudoku(int matrix[9][9]) {
    // Write your code here.
    return solve(matrix);
}

int main() {
    fast
    int matrix[9][9];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++)
        cin>>matrix[i][j];
    }
    isItSudoku(matrix) ? cout<<"YES" : cout<<"NO" ;
}