/*
    Time Complexity : O(N^2).
    N : Size of array.
*/

#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

void bubbleSort(vector<int> &arr, int &n) {
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(arr[i] > arr[j]) 
            swap(arr[i], arr[j]);
        }
    }
}

int main() {
    fast   

    cout << "\033[2J\033[1;1H";

    int n = 8;

    vector<int> arr = {1, 3, 2, 8, 2, 5, 6, 9};

    bubbleSort(arr, n); 

    for(auto i : arr)
    cout<<i<<' ';

    return 0;
}

