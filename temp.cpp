#include<bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

void solution() {
    int ns;
    cin>>ns;
    
    map<char, vector<char>> m;
    
    for(int i=1;i<=ns;i++) {
        char temp;
        cin>>temp;
        m[temp]={};
    }
    
    int na;
    cin>>na;
    
    
    for(int i=1;i<=na;i++) {
        char temp1, temp2;
        cin>>temp1>>temp2;
        m[temp1].push_back(temp2);
    }
    
    int q;
    cin>>q;
    int index;
    char j;
    for(int i=1;i<=q;i++) {
        vector<char> result;
        cin>>index;
        for(int k=1;k<=index;k++) {
            cin>>j;
            if(m[j].empty()) {
                result.push_back(j);
            }
        }
        
        cout<<result.size()<<" ";
        for(auto b : result)
        cout<<' '<<b;
        cout<<endl;
    }
}

int main()  {
    // YOUR CODE GOES HERE
    // Please take input and print output to standard input/output (stdin/stdout)
    // E.g. 'cin' for input & 'cout' for output
    fast
    int t;
    cin>>t;
    while(t--)
    solution();
    return 0;
}