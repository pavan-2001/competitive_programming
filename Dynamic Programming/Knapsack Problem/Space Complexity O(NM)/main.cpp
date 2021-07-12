/*
    Time Complexity : O(NM).
    Space Complexity : O(NM).
*/

#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'

void solution(int &n, int &m, vector<int> &weights, vector<vector<bool>> &dp) {
    dp[0][0] = true;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=m;j++) {
            if(j-weights[i] >= 0) {
                dp[i][j]  = dp[i][j] | dp[i-1][j - weights[i]];
            }
            dp[i][j] = dp[i][j] | dp[i-1][j];
        }
    }
}

int main() {
    fast
    int n = 4;
    vector<int> weights = {0, 1, 3, 3, 5};
    int m = accumulate(weights.begin(), weights.end(), 0);
    vector<vector<bool>> dp(n+1, vector<bool> (m+1, false));
    solution(n, m, weights, dp);
    for(int i=1;i<=m;i++) {
        if(dp[4][i] == true)
        cout<<i<<' ';
    }
    cout<<endl;

    return 0;
}