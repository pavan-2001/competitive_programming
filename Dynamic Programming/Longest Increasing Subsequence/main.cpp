#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

void solution(int &result, int &n, vector<int> &v) {
    vector<int> length(n, 0);

    for(int i=0;i<n;i++) {
        length[i] = 1;
        for(int j=0;j<i;j++) {
            if(v[j] < v[i]) {
                length[i] = max(length[i], length[j] + 1);
            }
        }
        result = max(result, length[i]);
    }
}

int main() {
    cout << "\033[2J\033[1;1H";
    fast
    int n = 8;
    vector<int> v={6, 2, 5, 1, 7, 4, 8, 3};
    int result=0;
    solution(result, n, v);
    cout<<result<<endl;
    return 0;
}