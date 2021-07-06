#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'



void myFunction(vector<string> &result, string &s, int i) {
    if(i == s.size() ){
        result.push_back(s);
        return ;
    }
   
     if(s[i] >= '0' && s[i] <= '9') {
            myFunction(result, s, i+1);
        } else {
            s[i] = toupper(s[i]);
            myFunction(result, s, i+1);
            s[i] = tolower(s[i]);
            myFunction(result, s, i+1);
        }
}

vector<string> letCasePermutation(string s) {
	// Write your code here
   	vector<string> result; 
    myFunction(result, s, 0);
   return result;
}

int main() {
    fast
    cout << "\x1b[2J\x1b[1;1H"<<endl;
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