/*
    https://www.codingninjas.com/codestudio/problems/arrangement_1235171
*/

#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'


vector<int> temp;
vector<bool> visited(15, false);

void myFunction(int &n, int &count) {
    if(temp.size() == n) {
        count++;
        return ;
    }

    for(int i=0;i<n;i++) {
        if(visited[i] == false) {
            if( ((temp.size()+1) % (i+1)) == 0 || ((i+1)%(temp.size()+1)) == 0) {
                temp.push_back(i+1);
                visited[i] = true;
                myFunction(n, count);
                visited[i] = false;
                temp.pop_back();
            }
        }
    }
}

int countArrangement(int N) {
	// Write your code here
    int count=0;
    myFunction(N, count);
    return count;
}



int main() {
    fast
    cout << "\x1b[2J\x1b[1;1H";
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        cout<<countArrangement(n)<<endl;;
    }
}