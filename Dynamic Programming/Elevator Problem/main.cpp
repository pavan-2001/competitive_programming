/*
    Time Complexity : O(2^N. N).
*/

#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

int solution(int &n, int &x, vector<int> &weights) {
    pair<int, int> best[1<<n];
    best[0] = {0, 0};
    for(int s = 1; s < (1<<n) ; s++) {
        best[s] = {n+1, 0};
        for(int p=0;p<n;p++) {
            if(s&(1<<p)) {
                auto option = best[s^(1<<p)];
                if(option.second + weights[p] <= x) {
                    option.second+=weights[p];
                } else {
                    option.first++;
                    option.second=weights[p];
                }
                best[s] = min(best[s], option);
            }
        }
    }
    
    return best[(1<<n)-1].first+1;
}

int main() {
    fast
    int x = 12, n = 5;
    vector<int> weights = {2, 3, 4, 5, 9};
    cout<<solution(n, x, weights)<<endl;
    return 0;
}