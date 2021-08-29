#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

tuple<int, int, int> bSearch(vector<vector<int>> &arr, int start, int end,int p1, int p2) {
    if(start >= end) {
        if(arr[start][0] < p1 && arr[start][1] < p2) {
            return make_tuple(arr[start][0], arr[start][1], start);
        }
        return make_tuple(-1, -1, -1);
    }
    
    int mid = (end + start)/2;
    auto r1 = bSearch(arr, start, mid, p1, p2);
    auto r2 = bSearch(arr, mid + 1, end, p1, p2);
    if(get<2>(r2) != -1 && get<1>(r2) < p2 && get<0>(r2) < p1)
        return r2;
    if(get<2>(r1) != -1 && get<1>(r1) < p2 && get<0>(r1) < p1)
        return r1;
    return make_tuple(-1, -1, -1);
}

int maxTowerHeight(vector<vector<int>> &arr, int n)
{
    // Write your code here.
    vector<int> dp(n, 0);
    
    sort(arr.begin(), arr.end());
    
    int best = 1;
    for(int i=0;i<n;i++) {
        auto r = bSearch(arr, 0, i-1, arr[i][0], arr[i][1]);
        cout<<get<0>(r)<<' '<<get<1>(r)<<' '<<get<2>(r)<<endl;
        if(get<2>(r) == -1)
            dp[i] = 1;
        else
            dp[i] = dp[get<2>(r)] + 1;
        best = max(best, dp[i]);
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    cout<<arr[i][0]<<' '<<arr[i][1]<<endl;
    cout<<endl;
    for(auto i : dp)
    cout<<i<<' ';
    cout<<endl;
    
    return best;
    
}

int main() {
    fast
    cout << "\033[2J\033[1;1H";
    vector<vector<int>> arr = {{5,4}, {5, 3}, {2, 3}, {2, 4}, {6, 3}, {6,4}};
    int n = 6;
    cout<<maxTowerHeight(arr, n)<<endl;
}