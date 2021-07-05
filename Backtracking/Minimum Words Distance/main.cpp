/*
    https://www.codingninjas.com/codestudio/problems/minimum-words-distance_1266044
*/

#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

int wordsDistance(string start, string end, int n, vector<string>& wordDic){
	// Write your code here
  
    auto it = find(wordDic.begin(), wordDic.end(), start);
    if(it == wordDic.end())
    return 0;
    auto it2 = find(wordDic.begin(), wordDic.end(), end);
    if(it2 == wordDic.end())
    return 0;

    return distance(it, it2);
}

int main() {
    fast
    string start = "ab", end = "xy";
    int n = 5;
    vector<string> wordDic = {"ab" , "xy" };
    int count = wordsDistance(start, end,n,  wordDic);
    cout<<count<<endl;
}