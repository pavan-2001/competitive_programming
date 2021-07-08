/*
 Time Complexity : O(n)
*/

#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

int maximumSubarray(vector<int> &arr, int n) {
    int best = 0, sum = 0;
    
    for(int i=0;i<n;i++) {
        sum = max(arr[i], sum+arr[i]);
        best = max(best, sum);
    }

    return best;
}

int main() {
    fast
    
    vector<int> arr={-1, 2, 4, -3, 5, 2, -5, 2};
    
    cout<<maximumSubarray(arr, 8)<<endl;

    return 0;
}