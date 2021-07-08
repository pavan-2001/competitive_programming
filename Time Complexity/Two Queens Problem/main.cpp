/*
Problem Statement : 
Given an N X N chess board , count the number of ways to place 2 Queens on the board in such a way that they do not attack each other.

Time Complexity : O(1).

q(n) = (n^4/2) - 5(n^3)/3 + 3(n^2)/2 - n/3;

*/

#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'

int solution(int n) {
    
    int n4 = pow(n ,4);
    int n3 = pow(n, 3);
    int n2 = pow(n, 2);
    int result = (ceil)(n4/2) - (ceil)(5*n3)/3 + (ceil)(3*n2)/2 - (ceil)(n/3);

    return result;
}

int main() {
    fast
    cout << "\033[2J\033[1;1H";
    int n = 10;
    cout<<solution(n)<<endl;

    return 0;
}