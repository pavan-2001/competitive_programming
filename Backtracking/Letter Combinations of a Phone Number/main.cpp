#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'


string temp;

void myFunction(vector<string> &result,string &s, int start, string m[]) {
    if(start >= s.size()) {
        result.push_back(temp);
        return ;
    }
    
    int num = s[start] - '0';
    
    for(int i=0;i<m[num].size();i++) {
        temp.push_back(m[num][i]);
        myFunction(result, s, start+1, m);
        temp.pop_back();
    }
}

vector<string> combinations(string s){
	
	// Write your code here
   string m[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 

    vector<string> result;

    myFunction(result, s, 0, m);

    return result;
	
}

int main() {
    fast
    cout << "\033[2J\033[1;1H";
    string s = "234";
    auto result = combinations(s);

    for(auto i : result)
    cout<<i<<' ';
    cout<<endl;
    return 0;
}