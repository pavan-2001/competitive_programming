/*
    https://www.codingninjas.com/codestudio/problems/flood-fill_1082141
*/

#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'

bool isValid(vector<vector<int>> &image, int x, int y, int n, int m, int value) {
    if(x < 0 || x >= n || y < 0 || y>= m || image[x][y] != value) {
        return false;
    }
    return true;
}

void solve(vector<vector<int>> &image, int x, int y, int n, int m, int p, int value) {
    image[x][y] = p;
    if(isValid(image, x+1, y, n, m, value)) {
        solve(image,x+1, y, n, m, p, value);
    }
    if(isValid(image, x-1, y, n, m, value)) {
        solve(image, x-1, y, n, m, p, value);
    }
    if(isValid(image, x, y+1, n, m, value)) {
        solve(image, x, y+1, n, m, p, value);
    }
    if(isValid(image, x, y-1, n, m, value)) {
        solve(image, x, y-1, n, m, p, value);
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int n, int m, int x, int y, int p) {
	// Write your code here.
    solve(image, x, y, n, m, p, image[x][y]);
    vector<vector<int>> result = image;
    return result;
}

int main() {
    fast;
    int t;
    cin>>t;
    while(t--) {
        int n, m, x, y, p;
        cin>>n>>m>>x>>y>>p;
        vector<vector<int>> image(n,vector<int>(m));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++)
            cin>>image[i][j];
        }
        auto result = floodFill(image, n, m, x, y, p);
        for(int i=0;i<result.size();i++) {
            for(auto a : result[i])
            cout<<a<<' ';
            cout<<endl;
        }
    }
}