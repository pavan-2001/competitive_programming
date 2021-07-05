#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

string temp;

void myFunction(vector<string> &result, string &s, int start) {
    if(temp.size() == s.size()) {
        //cout<<temp;
        result.push_back(temp);
        return ;
    }
    for(int i=start;i<s.size();i++) {
        temp.push_back(tolower(s[i]));
        myFunction(result, s, i+1);
        temp.pop_back();
        temp.push_back(toupper(s[i]));
        myFunction(result, s, i+1);
        temp.pop_back();
    }
}

vector<string> letCasePermutation(string s) {
	// Write your code here
    vector<string> result;
    myFunction(result, s, 0);
    sort(result.begin(), result.end());
    auto it = unique(result.begin(), result.end());
    result.erase(it, result.end());
    return result;
}

int main() {
    fast
    //cout << "\x1b[2J\x1b[1;1H"<<endl;
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        vector<string> result = letCasePermutation(s);
        for(auto i : result)
        cout<<i<<endl;
    }
}