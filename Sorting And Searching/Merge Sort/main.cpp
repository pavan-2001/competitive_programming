/*
    Time Complexity : O(Nlog(N)).
    N : Size of the array

*/

#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

void merge(vector<int> &arr, int start1, int end1, int start2, int end2) {
    vector<int> vec1;
    vector<int> vec2;

    for(int i=start1;i<=end1;i++) {
        vec1.push_back(arr[i]);
    }
    
    for(int i=start2;i<=end2;i++) {
        vec2.push_back(arr[i]);
    }

    int index=start1;
    end1-=start1;
    end2-=start2;
    start1=0;
    start2=0;

    while(start1 <= end1 && start2 <= end2) {
        if(vec1[start1] <= vec2[start2]) {
            arr[index] = vec1[start1];
            start1++;
        } else {
            arr[index] = vec2[start2];
            start2++;
        }

        index++;
    }
    if(start1 <= end1) {
        arr[index] = vec1[start1];
        start1++;
        index++;
    }
    if(start2 <= end2) {
        arr[index] = vec2[start2];
        start2++;
        index++;
    }

    return ;
}

void mergeSort(vector<int> &arr, int start, int end) {
    if(start >= end) {
        return ;
    }

    int mid = (start+end)/2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, start,mid, mid+1, end);
}

int main() {
    fast   

    cout << "\033[2J\033[1;1H";

    int n = 8;

    vector<int> arr = {1, 3, 2, 8, -2, 5, 6, -9};

    mergeSort(arr, 0, n-1); 

    for(auto i : arr)
    cout<<i<<' ';

    return 0;
}

