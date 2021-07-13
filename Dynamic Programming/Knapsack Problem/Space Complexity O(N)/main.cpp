/*
    Time Complexity : O(NM).
    space Complexity : O(M).
*/

#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define encl '\n'

vector<int> solution(vector<int> &weights, int &n) {
    int m = accumulate(weights.begin(), weights.end(), 0);
    vector<int> sums(m+1, 0);

    sums[0] = 1;

    for(int i=1;i<n;i++) {
        for(int j = m-weights[i]; j>=0;j--) {
            sums[j+weights[i]] |= sums[j];
        }
    }

    return sums;
}

int main() {
    fast
    int n = 5;
    vector<int> weights = {0, 1, 3, 3, 5};
    auto result = solution(weights, n);

    for(int i=1;i<result.size();i++) {
        if(result[i] == 1)
        cout<<i<<' ';
    }

    return 0;
}