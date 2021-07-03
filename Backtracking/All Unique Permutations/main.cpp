/*
    https://www.codingninjas.com/codestudio/problems/all-unique-permutations_1094902
*/

#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

vector<bool> chosen(6, false);
vector<int> number;

void solve(vector<vector<int>> &s, vector<int> &arr, int n, vector<vector<int>> &result) {
    if(number.size() == n) {
        result.push_back(number);
        return ;
    }
    for(int i=0;i<n;i++) {
        if(chosen[i] == true) continue;
        chosen[i] = true;
        number.push_back(arr[i]);
        solve(s, arr, n, result);
        chosen[i] = false;
        number.pop_back();
    }
    return ;
}

vector<vector<int> > uniquePermutations(vector<int> &arr, int n) {
	// Write your code here.
    vector<vector<int> > s;
    vector<vector<int>> result;
    solve(s, arr, n , result);
    sort(result.begin(), result.end());
    auto it = unique(result.begin(), result.end());
    result.erase(it, result.end());
    return result;
}

int main() {
    fast
    vector<int> arr={1, 2, 3};
    int n = 3;
    auto result=uniquePermutations(arr, n);
    for(int i=0;i<result.size();i++) {
        for(auto a : result[i])
        cout<<a << ' ';
        cout<<endl; 
    }
}