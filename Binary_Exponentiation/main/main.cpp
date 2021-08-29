#include<bits/stdc++.h>
using namespace std;

long long Binary_exponentiation(long long a, long long n) {
    if(n == 0)
    return 1;

    long long result = 1;

    while(n) {
        if((n&1)) {
            result = result * a;
        }
        n = (n>>1);
        a = a*a;
    }

    return result;
}

int main() {
    long long a = 3;
    long long n = 13;
    cout<<Binary_exponentiation(a, n)<<endl;
}