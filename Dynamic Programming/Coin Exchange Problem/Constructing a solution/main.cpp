/*
    Iterative Approach ( Bottom to top ) - (Memoization)
    Time Complexity : O(N.K) {N : sum to be made, K : number of denominations}.
    this iterative approach is bottom to top it calculates solution for every subproblem or we can say number fro 1 to n.
    then uses those values to calculate the answer for bigger number .
*/


#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

const int n = 15;

int coins[3] = {1, 3, 4};

int value[n+1];

int first[n+1];

int main() {
    fast
    cout << "\033[2J\033[1;1H";

    value[0] = 0;

    for(int i=1;i<=n;i++) {
        value[i] = 1e9;

        for(auto c : coins) {
            if(i - c >= 0 && value[i-c]  + 1 < value[i]) {
                value[i] = value[i - c] + 1;
                first[i] = c;
            }
        }
    }

    cout<<"The solution is : "<<endl;

    int x = n;
    while(x > 0) {
        cout<<first[x]<<' ';
        x-=first[x];
    }


    return 0;
}