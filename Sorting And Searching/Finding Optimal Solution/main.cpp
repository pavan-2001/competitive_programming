/*
    Time Complexity : O(Nlog(Z))
    z : upper bound
    
    Problem Statement
    Consider a problem where our task is to process k jobs using n machines. Each machines is assigned an integer pi : the time to process a single job. 
    What is the minimum time to process all jobs?
*/

#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

bool valid(vector<int> &arr, int x, int tasks) {
    
    int temp = 0;
    for(int i=0;i<arr.size(); i++) {
        temp += (floor)(x/arr[i]);
        if(temp >= tasks)
        return true;
    }

    return false;
}

int minTimeToProcessTasks(vector<int> &p, int tasks, int machines, int z) {
    int x=-1;

    for(int b = z; b>=1 ;b/=2) {

        while(!valid(p, x+b, tasks)) {
            x+=b;
        }
    }


    return x+1;
}

int main() {
    fast   

    cout << "\033[2J\033[1;1H";

    int tasks = 8;

    int machines = 3;

    vector<int> p = {2, 3, 7};

    cout<<minTimeToProcessTasks(p, tasks, machines, 16)<<endl;

    return 0;
}

