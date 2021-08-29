#include<bits/stdc++.h>
using namespace std;

bool isCyclic = false;

void TopologicalSort(int node, vector<int> &state, list<int> &FullyProcessedNodes, vector<int> adj[]) {
    
    // Condition for checking if the graph is cyclic.
    if(state[node] == 1) {
        // Condition for checking if the graph is cyclic.
        cout<<"This Graph Contains Cycle"<<endl;
        isCyclic = true;
        return ;
    }

    // The node has been processed
    if(state[node] == 2)
    return ;

    // The node is under processing
    state[node] = 1;

    // traversing the adjecency list of the node
    for(int i=0;i<adj[node].size();i++) {
        TopologicalSort(adj[node][i], state, FullyProcessedNodes, adj);
    }

    // After all the edges from the node has been visited, so its state becomes 2 
    state[node] = 2;

    // appending it to the list 
    FullyProcessedNodes.push_back(node);

    return ;
}

int main() {

    // clear screen string 
    cout << "\033[2J\033[1;1H";

    isCyclic = false;

    // number of nodes in the graph
    int n = 6;
    
    // new vector to store the states of each nodes.
    vector<int> state(n, 0);

    // adjecency list
    vector<int> adj[n] = {{1}, {2}, {4, 5}, {0, 4}, {1}, {}};

    // List to hold the nodes whose state is 2
    list<int> FullyProcessedNodes;

    // Loop for Calling topological sort on unprocessed nodes
    for(int i=0;i<n;i++) {
        TopologicalSort(i, state, FullyProcessedNodes, adj);
    }

    // Reverse the list after processing all the nodes
    FullyProcessedNodes.reverse();

    if(!isCyclic){
        // Printing the List of nodes
        for(auto i : FullyProcessedNodes)
        cout<<i<<' ';
    }

    return 0;
}

// Time Complexity (same as DFS) : O(V + E).
// Space Complexity : O(V). 