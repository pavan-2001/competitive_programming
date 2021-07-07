#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'

void solution( vector<int> &v, int &n) {
    int best=0, sum = 0;

    for(int i=0;i<n;i++) {
        sum = max(v[i], sum+v[i]);
        best = max(best, sum);
    }

    cout<<best<<endl;

    return ;
}

int main() {
    fast
    int n = 8;
    vector<int> v = {-1, 2, 4, -3, 5, 2, -5, 2};
    solution(v, n);
}