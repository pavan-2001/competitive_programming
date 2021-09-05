#include<bits/stdc++.h>
using namespace std;

void TopologicalSort(int &n, vector<int> adj[], int i, vector<bool> &visited, vector<int> &q) {
    if(visited[i])
    return ;

    for(auto j : adj[i]) {
        TopologicalSort(n,adj, j, visited, q);
    }

    visited[i] = true;
    q.push_back(i);

    return ;
}

int CountingNumberOfPaths(int &start, int &end, int &n, vector<int> adj[], vector<int> &paths) {
    vector<bool> visited(n, false);
    vector<int> q;

    // Topological sort
    for(int i=0;i<n;i++){
        if(!visited[i]){
            TopologicalSort(n, adj, i, visited, q);
        }
    }

    // reversing the list
    reverse(q.begin(), q.end());

    
    paths[start] = 1;

    // traversing according to topological sort
    for(int i=0;i<n;i++) {
        for(auto j : adj[q[i]]) {
            paths[j] += paths[q[i]];
        }
    }

    return paths[end];
}

int main() {

    // using dynamic programming to solve the number of shortest paths from source to sink. 
    
    // clear screen string 
    cout << "\033[2J\033[1;1H";

    // number of nodes 
    int n = 6;
    
    // stores the number of paths
    vector<int> paths(n, 0);

    // source node
    int start = 0;

    // destination node
    int end = 5;

    // adjecency list 
    vector<int> adj[n] = {{1, 3}, {2, 5}, {5}, {4}, {1}, {}};

    auto NumberOfPaths = CountingNumberOfPaths(start, end, n, adj, paths);

    cout<<NumberOfPaths<<endl;

    return 0;
}

// Time Complexity : O(V.E).
// Space Complexity : O(V).