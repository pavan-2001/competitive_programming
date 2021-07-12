#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

const int n = 5;

int coins[3] = {1, 3, 4};

int count1[n+1];

int main() {
    fast
    cout << "\033[2J\033[1;1H";

    count1[0] = 1;

    for(int i=1;i<=n;i++) {
        for(auto c : coins) {
            if(i - c >= 0 ) {
                count1[i] += count1[i - c];
            }
        }
    }



    cout<<"The no of possible solutions is : "<<count1[n]<<endl;
}