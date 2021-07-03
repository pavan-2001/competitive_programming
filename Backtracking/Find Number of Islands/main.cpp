/*
    https://www.codingninjas.com/codestudio/problems/find-number-of-islands_630512
*/

#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

const int N=1000, M =1000;
vector<vector<bool>> visited(N, vector<bool>(M, false));

void  visiting(int **arr, int row, int col, int n, int m) {
    visited[row][col] = true;
   if(row - 1 >= 0  && col - 1 >= 0 && arr[row-1][col - 1] == 1 && visited[row-1][col-1] == false )
   visiting(arr, row - 1, col -1, n, m);
   if(row - 1 >= 0  && col >= 0 && arr[row-1][col] == 1 && visited[row-1][col] == false )
   visiting(arr, row - 1, col , n, m);
   if(row - 1 >= 0  && col + 1 < m && arr[row-1][col + 1] == 1 && visited[row-1][col+1] == false )
   visiting(arr, row - 1, col+1, n, m);
   if(row >= 0  && col - 1 >= 0 && arr[row][col - 1] == 1 && visited[row][col-1] == false )
   visiting(arr, row , col-1, n, m);
   if(row >= 0  && col + 1 < m && arr[row][col + 1] == 1 && visited[row][col+1] == false )
   visiting(arr, row, col+1, n, m);
   if(row + 1 < n  && col - 1 >= 0 && arr[row+1][col - 1] == 1 && visited[row+1][col-1] == false )
   visiting(arr, row + 1, col -1, n, m);
   if(row + 1 < n  && col  >= 0 && arr[row+1][col ] == 1 && visited[row+1][col] == false )
   visiting(arr, row + 1, col , n, m);
   if(row + 1 < n  && col + 1 < m && arr[row+1][col + 1] == 1 && visited[row+1][col+1] == false )
   visiting(arr, row+1, col+1, n, m);
   return ;
}

void solve(int **arr, int &n, int &m, int row, int &count) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(arr[i][j] == 1 && visited[i][j] == false) {
                count++;
                visiting(arr, i, j, n, m);
            }
        }
    }
    return ;
}

int getTotalIslands(int** arr, int n, int m)
{
    int count=0;
    solve(arr, n, m, 0, count);
    return count;
}


int main() {

    fast 
    int n=4, m=4;
    int **arr = new int*[n];
    for(int i=0;i<m;i++) {
        arr[i] = new int[m];
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++)
        cin>>arr[i][j];
    }
    cout<<getTotalIslands(arr, n, m)<<endl;
    return 0;
}