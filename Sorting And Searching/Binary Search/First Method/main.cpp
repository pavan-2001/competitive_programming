/*
    Time Complexity : O(log(N)).
    N : Maximum number in arr

*/

#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

int binarySearch(vector<int> &arr, int n, int toSearch) {
    int a = 0, b = n-1;
    while(a<=b) {
        int mid = (a+b)/2;
        if(arr[mid] == toSearch) {
            return mid;
        }
        if(arr[mid] < toSearch) a = mid+1;
        else b=mid-1;
    } 
    return -1;
}

int main() {
    fast   

    cout << "\033[2J\033[1;1H";

    int n = 8;

    vector<int> arr = {1, 3, 2, 8, 2, 5, 6, 9};

    cout<<binarySearch(arr, n ,-9);

    return 0;
}

