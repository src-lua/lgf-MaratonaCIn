#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

const int p = 1e9+7;

 
ll power(ll base, ll exp){
    ll resp = 1;
    base %= p;
    while(exp > 0){
        if(exp % 2 == 1)resp = (resp*base)%p;
        base = (base*base)%p;
        exp /= 2;
    }
    return resp;
}
 
ll modinverse(ll n){
    return power(n, p-2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << modinverse(2);

    return 0;
}