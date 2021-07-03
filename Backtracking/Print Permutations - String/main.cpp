/*
    https://www.codingninjas.com/codestudio/problems/print-permutations-string_758958
*/

#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

string temp;
vector<bool> chosen(8, false);

void solve(vector<string> &result, string &s) {
    if(temp.size() == s.size()) {
        result.push_back(temp);
        return ;
    }
    for(int i=0;i<s.size();i++) {
        if(chosen[i] == true) continue;
        chosen[i] = true;
        temp.push_back(s[i]);
        solve(result, s);
        chosen[i] = false;
        temp.pop_back();
    }
    return ;
}

vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string> result;
    solve(result, s);
    return result;
}

int main() {
    fast
    string s  = "cba";
    auto result = findPermutations(s);
    for(auto a : result)
    cout<<a<<endl;
}