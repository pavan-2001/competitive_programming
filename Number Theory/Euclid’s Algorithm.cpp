#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
  if(b == 0)
    return a;
  return gcd(b, a%b);
}

int main(){
    int res = gcd(30, 12);
    cout<<res<<endl;
  return 0;
}
