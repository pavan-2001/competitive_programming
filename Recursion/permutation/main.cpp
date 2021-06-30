#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define freopen freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

vector<int> permutation;
const int n=3;
bool chosen[n+1];

void search() {
	if(permutation.size() == n) {
		for(auto i : permutation)
		cout<<i<<' ';
		cout<<endl;
	} else {
		for(int i=1;i<=n;i++) {
			if(chosen[i] == true) continue;
			chosen[i] = true;
			permutation.pb(i);
			search();
			permutation.pop_back();
			chosen[i] = false;
		}
	}
	return ;
}

int main() {
	fast
	search();
}