#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'

vector<string> temp;

bool isPalindrome(int &start, int &end, string &S) {
    while(start < end) {
        if(S[start] != S[end]) 
        return false;

        start++;
        end--;
    }
    return true;
}

void myFunction(vector<vector<string>> &solution, string S, int start) {
    if(start >= S.size()) {
        solution.push_back(temp);
        return ;
    }
    for(int i=start;i<S.size();i++) {
        if(isPalindrome(start, i, S)) {
            temp.push_back(S.substr(start, i+1));
            myFunction(solution, S, i+2);
            temp.pop_back();
        }
    }
}

vector<vector<string>> partition(string S) {
    // Write your code here
	vector<vector<string>> solution;
    myFunction(solution, S, 0);
    return solution;
}

int main() {
    cout << "\033[2J\033[1;1H";
    fast
    string S = "BaaB";
    auto result = partition(S);
    for(int i=0;i< result.size();i++) {
        for(auto a : result[i])
        cout<<a <<' ';
        cout<<endl;
    }
}