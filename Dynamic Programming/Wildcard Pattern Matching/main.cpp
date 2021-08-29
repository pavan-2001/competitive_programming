#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

bool wildcardMatching(string pattern, string text)
{
   // Write your code here.
    int n = text.size();
    int m = pattern.size();
    vector<vector<int>> dp(m+2, vector<int>(n+2, 0));
    
    for(int i=1;i<=m;i++) {
        for(int j=1;j<=n;j++) {
            if(pattern[i-1] == '?') {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else if(pattern[i-1] == '*') {
                dp[i][j] = max(dp[i-1][j-1] + 1, max(dp[i][j-1] + 1, dp[i-1][j]));
            } else if(pattern[i-1] == text[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
        }
    }

    // for(int i=0;i<=m;i++) {
    //     for(int j=0;j<=n;j++)
    //     cout<<dp[i][j]<<' ';
    //     cout<<endl;
    // }
    
    return dp[m][n] == n ? true : false ;
}


int main() {
    fast
    cout << "\033[2J\033[1;1H";
    string pattern = "ab*d";
    string text = "abd";
    cout<<"--------------------------------------------------------"<<endl;
    int x = 424242;
    bitset<32> a(x);
    cout<<x<<endl;
    for(int i=31;i>=0;i--)
    cout<<a[i]<<' ';
    cout<<endl;
    int num = 268435455;
    bitset<32> a1(num);
    for(int i=31;i>=0;i--) {
        cout<<a1[i]<<' ';
    }
    cout<<endl;
    bitset<32> a2(x&num);
    for(int i=31;i>=0;i--)
    cout<<a2[i]<<' ';
    cout<<endl;
    cout<<endl;
    for(int i=1;i<=26;i++) {
        x = ((x<<5) + x) + i;
        x = x & 268435455;
        cout<<x<<endl;
        bitset<32> b(x);
        for(int i=31;i>=0;i--)
        cout<<b[i]<<' ';
        cout<<endl;
        cout<<endl;
    }
}