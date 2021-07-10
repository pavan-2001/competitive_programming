/*
    Recursive Approach ( Top to Bottom ) 
    Time Complexity : O(N.K) {N : sum to be made, K : number of denominations}
    we call solve function with an argument n;
    for which it calculates the minimum number of coins required to form that sum.
    if n becomes less than 0 that means we cannot form a negative sum so then we return infinity.
    if n becomes 0 ,we return 0 . because no coins are required to make 0.
    if x is greater tha 0 we go through every denomination of the coin + 1.
                { n < 0  , INFINITY
    solve(n) =  { n == 0 , 0
                { n > 0 , solve(n-c)+1, c belongs to coins
*/


#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

int arr[3] = {1, 3, 4};

int solve(int n) {
    if(n < 0)
    return 1e9;

    if(n == 0)
    return 0;

    int best=1e9;

    for(auto c : arr) {
        best = min(best, solve(n-c)+1);
    }

    return best;
}

int main() {
    fast
    cout << "\033[2J\033[1;1H";
    int n = 10;
    cout<<"The Minimum coins required to from the sum is : "<<solve(n)<<endl;
}