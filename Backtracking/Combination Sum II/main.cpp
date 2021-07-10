#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

void myFunction(vector<vector<int>> &result, vector<int> arr, int &n, int &target, int start, vector<int> &temp, int &sum) {
    
    if(sum == target) {
        result.push_back(temp);
        return ;
    }
    if(start >= n || sum > target) 
        return ;
    
    for(int i=start;i<n;i++) {
        if(sum+arr[i] <= target) {
            temp.push_back(arr[i]);
            sum+=arr[i];
            myFunction(result, arr, n, target, i+1, temp, sum);
            temp.pop_back();
            sum-=arr[i];
        }
    }
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	// Write your code here.
    sort(arr.begin(), arr.end());
    vector<vector<int>> result;
    vector<pair<int, int>> freq(31, {0,1e9});
    vector<int> temp;
    int sum=0;

    
    for(int i=0;i<n;i++) {
        freq[arr[i]].first++;
        freq[arr[i]].second = min(i, freq[arr[i]].second);
    }

    // for(int i=1;i<31;i++) {
    //     if(freq[i].first != 0) {
    //         cout<<i<<' '<<freq[i].second<<endl;
    //     }
    // }
    
    for(int i=1;i<31;i++) {
        if(freq[i].first!=0 && i <= target) {
            vector<int> temp(freq[i].first, i);
            sum=i*freq[i].first;
           for(int j=1;j<=freq[i].first;j++) {
               myFunction(result, arr, n, target, freq[i].second + freq[i].first, temp, sum);
               temp.pop_back();
               sum-=i;
           }
           sum=0;
        }
    }
    
   
    return result;
}


int main() {
    // fast
    cout << "\033[2J\033[1;1H";
    int n = 6, target = 10;
    vector<int> arr = {1, 2, 2, 3, 1, 5};

    auto result = combinationSum2(arr, n, target);

    for(int i=0;i<result.size();i++) {
        for(auto j : result[i])
        cout<<j<<' ';
        cout<<endl;
    }
}