#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

vector<int> number;


void solve(vector<int> &result, int n, int k) {
    if(number.size() == n) {
       int temp=number[0];
       for(int i=1;i<n;i++) {
           temp *= 10;
           temp = temp + number[i];
       }
       result.push_back(temp);
        return ;
    }
    for(int i=0;i<=9;i++) {
        if(number.size() != 0) {
            if(abs(number[number.size()-1] - i) == k) {
                number.push_back(i);
                solve(result, n, k);
                number.pop_back();
            }
        } else if(number.size() == 0 && i != 0){
            number.push_back(i);
            solve(result, n, k);
            number.pop_back();
        }
    }
}

vector<int> numberWithSameConsecutiveDifference(int N, int K)
{
	
	// Write your code here
    vector<int> result;
    solve(result, N ,K);
	return result;
}
int main() {
    fast
    int n = 3, k = 6;
    auto result = numberWithSameConsecutiveDifference(n ,k);
    for(int i=0;i<result.size();i++)
    cout<<result[i]<<' ';
}