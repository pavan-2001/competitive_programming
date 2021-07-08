/*
    Time Complexity : O(N).
    N : Maximum number in arr

*/

#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

void countingSort(vector<int> &arr, int &n) {
    int max_num = -1e9;

    for(int i=0;i<n;i++) {
        max_num = max(arr[i], max_num);
    }

    vector<int> temp(max_num+1, 0);

    for(int i=0;i<n;i++) {
        temp[arr[i]]++;
    }

    vector<int> index(max_num+1, 0);
    for(int i=1;i<=max_num;i++) {
        index[i] = index[i-1] + temp[i];
    }

    for(int i=0;i<=max_num;i++) {
        while(temp[i]>0) {
            arr[index[i]-1] = i;
            index[i]--;
            temp[i]--;
        }
    }

}

int main() {
    fast   

    cout << "\033[2J\033[1;1H";

    int n = 8;

    vector<int> arr = {1, 3, 2, 8, 2, 5, 6, 9};

    countingSort(arr, n); 

    for(auto i : arr)
    cout<<i<<' ';

    return 0;
}

