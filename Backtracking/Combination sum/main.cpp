#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

int sum=0;
vector<int> temp;

void myFunction(vector<vector<int>> &result, vector<int> &arr, int b, int start) {
    
    if(sum == b) {
        result.push_back(temp);
        return ;
    }
    if(start == arr.size())
        return ;
    
    for(int i=start;i<arr.size();i++) {
        if(sum+arr[i] <= b) {
            sum+=arr[i];
            temp.push_back(arr[i]);
            myFunction(result, arr, b, i);
            sum-=arr[i];
            temp.pop_back();
        } else {
            return ;
        }
    }
}

vector<vector<int>> combSum(vector<int>& ARR, int B)
{
	// Write your code here
	// Return a vector of sorted vectors/combinations
    vector<vector<int>> result;
    sort(ARR.begin(), ARR.end());
    myFunction(result, ARR, B, 0);
    return result;
}


int main() {
    fast
    cout << "\x1b[2J\x1b[1;1H"<<endl;
    int t;
    cin>>t;
    while(t--) {
        int n ,b;
        cin>>n >>b;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        cin>>arr[i];
        auto result = combSum(arr, b);
        for(int i=0;i<result.size();i++) {
            for(auto j : result[i])
            cout<<j<<" ";
            cout<<endl;
        }
    }
}