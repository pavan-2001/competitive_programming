#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define freopen freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int n = 1;
int count_combinations = 0;

vector<int> col(n,0); // for finding combinations
vector<int> diag1(n+(n-1), 0); // for finding combinations
vector<int> diag2(n+(n-1), 0); // for finding combinations
vector<vector<int>> board(n, vector<int>(n, 0)); // for finding possible arrangement

// this function checks if we place our queen at current position it's not attacking any queen at y th column and the diagonals  
bool isSafe(int x, int y) {
    
    int row = x;
    int col = y;
    // for column
    for(int i=row; i >= 0; i--) {
        if(board[i][col] == 1)
        return false;
    }
    // for diagonal1
    while(row >= 0 && col >= 0) {
        if(board[row][col] == 1) 
        return false;
        row--;
        col--;
    }
    row = x;
    col = y;
    // for diagonal 2
    while(row >= 0 && col < n) {
        if(board[row][col] == 1)
        return false;
        row--;
        col++;
    }
    // else return true if no queen is placed in its attacking positions 
    return true;
}

bool search(int x) {
    // if we have placed all the n queens then simply return true
    if(x == n) {
        return true;
    } 
    // else check for the desired position to place the xth queen at xth row...
    for(int i=0;i<n;i++) {
        // check is it safe to place the queen at xth row and ith column
        if(isSafe(x, i)) {
            // if its true assign 1 to this place and recurse to place the (x+1)th queen in (x+1)th row 
            board[x][i] = 1;
            // if it successfully placed the rest of the queens then return true.
            if(search(x+1)) {
                return true;
            } else { // if its false it means there is no way to place a queen further from this position so change it to 0 and move forward.
                board[x][i] = 0;
            }
        }
    }
    // return false if there is now way to place queen with current arrangement
    return false;
}

//  This function is to find the no. of possible combinations to place n queens on n x n chess board
void combinations(int x) { // x denotes xth row
    if(x == n) { // if x has passed the last row it means we have placed all the queens successfully. so we have got a combinations so increment the count by 1. 
        count_combinations++;
        return ;
    }
    for(int i=0;i<n;i++) { // else find if its possible to place the queen 
        if(col[i] || diag1[i+x] || diag2[i-x+n-1]) continue ; // check if there a queen to its col or one of its diagonals if true continue else place the xth queen here 
        col[i] = diag1[i+x] = diag2[i-x+n-1] = 1;
        combinations(x+1);
        // we are re-tracing 
        col[i] = diag1[i+x] = diag2[i-x+n-1] = 0;
    }
}

int main() {
	fast
    combinations(0);
    search(0);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++)
        cout<<board[i][j]<<' ';
        cout<<endl;
    }
    cout<<"The number of possible combinations are : "<<count_combinations<<endl;
}