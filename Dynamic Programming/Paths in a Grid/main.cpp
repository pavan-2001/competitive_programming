/*
    Time Complexity : O(N^2)
*/

#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

void solution(int &result, vector<vector<int>> &grid, int &n) {
    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
    }
    result = dp[n][n];
}

int main() {
    cout << "\033[2J\033[1;1H";
    fast
    int n=5;
    vector<vector<int>> grid = {{0, 0, 0, 0, 0, 0}, {0, 3, 7, 9, 2, 7}, {0, 9, 8, 3, 5, 5}, {0, 1, 7, 9, 8, 5}, {0, 3, 8, 6, 4, 10}, {0, 6, 3, 9, 7, 8}};
    int result=0;
    solution(result, grid, n);
    cout<<result<<endl;
}