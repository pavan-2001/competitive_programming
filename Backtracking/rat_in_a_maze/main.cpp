/*
https://www.codingninjas.com/codestudio/problems/rat-in-a-maze_1215030
*/

#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

string path;
vector<vector<int>> visited(5, vector<int>(5, 0));


bool isSafe(int x, int y, int n, vector<vector<int >> &arr) {
    if(x == n || x < 0 || y == n || y < 0 || visited[x][y] == 1 || arr[x][y] == 0)
    return false;

    return true;
}

void combinations(vector<string> &solution, int x, int y, int n, vector<vector<int >> &arr) {
    if(x == n-1 && y == n-1) {
        solution.push_back(path);
        return ;
    }
    if(x<0 || y < 0 || x == n || y == n||arr[x][y] == 0 || visited[x][y] == 1 )
    return ;

    visited[x][y] = 1;
    if(isSafe(x+1, y, n, arr)) {
        path.push_back('D');
        combinations(solution, x+1, y, n, arr);
        path.pop_back();
    } 
    if(isSafe(x, y-1, n, arr)) {
        path.push_back('L');
        combinations(solution, x, y-1, n, arr);
        path.pop_back();
    } 
    if(isSafe(x, y+1, n, arr)) {
        path.push_back('R');
        combinations(solution, x, y+1, n, arr);
        path.pop_back();
    }
    if(isSafe(x-1, y, n, arr)) {
        path.push_back('U');
        combinations(solution, x-1, y, n, arr);
        path.pop_back();
    } 
    visited[x][y] = 0;
    
}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    // Write your code here.
    vector<string> solution;
    combinations(solution,  0, 0, n, arr);
    return solution;
}

int main() {
    fast
    int n;
    cin>>n;
    vector<vector<int>> arr(n, vector<int>(n, 0));
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>arr[i][j];
        }
    }
    vector<string> result = searchMaze(arr, n);
    for(auto i : result)
    cout<<i<<endl;
}
