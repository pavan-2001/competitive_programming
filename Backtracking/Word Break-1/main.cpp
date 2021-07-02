#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl '\n'

vector<string> solution;

bool isSafe(string &sentence, string s, vector<string> &dictionary) {
    //cout<<s<<endl;
    for(int i=0;i<dictionary.size();i++) {
        if(dictionary[i] == s)
        return true;
    }

    return false;
}

void solve(vector<string> &result, string sentence, vector<string> &dictionary) {
    if(sentence.empty()) {
        string temp;
        for(int i=0;i<solution.size();i++) {
            temp+= solution[i] + ' ';
        }
        //cout<<temp<<endl;
        temp.pop_back();
        result.push_back(temp);
    }
        for(int j=1;j<=sentence.size();j++) {
            if(isSafe(sentence, sentence.substr(0, j), dictionary)) {
                solution.push_back(sentence.substr(0, j));
                solve(result, sentence.substr(j), dictionary);
                solution.pop_back();
            }
    }
}

vector<string> getAllValidSentences(string &sentence, vector<string> &dictionary)
{
    //  write your code here.
    vector<string> result;
    solve(result, sentence, dictionary);
    return result;
}

int main() {
    fast;
    int n = 6;
    string sentence = "godisnowherenowhere";
    vector<string> dictionary(4);
    dictionary = {"god", "is", "now", "no", "where", "here"};
    vector<string> result = getAllValidSentences(sentence, dictionary);

        for(auto a : result)
        cout<<a<<endl;
}