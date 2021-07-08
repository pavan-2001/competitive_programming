/*
    Time Complexity : O(log(N)).
    N : Maximum number in arr

*/

#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

int binarySearch(vector<int> &arr, int n, int toSearch) {
    int  k = 0;
    for(int i=n/2; i > 0;i/=2) {
        while((k+i) < n && arr[k+i] <= toSearch) k+=i;
    }
    if(arr[k] == toSearch)
    return k;

    return -1;
}

int main() {
    fast   

    cout << "\033[2J\033[1;1H";

    int n = 8;

    vector<int> arr = {1, 3, 2, 8, 2, 5, 6, 9};

    cout<<binarySearch(arr, n ,9);

    return 0;
}

