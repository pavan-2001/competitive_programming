#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define freopen freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


vector<int> subset;
int n=0;

void search(int k) {
    if(k == n+1) {
        cout<<"{ ";
        for(auto i: subset)
        cout<<i<<' ';
        cout<<"}"<<endl;
    } else {
        subset.pb(k);
        search(k+1);
        subset.pop_back();
        search(k+1);
    }
    return ;
}

int main() {
	fast
    n = 3;
    search(1);
}