#include <bits/stdc++.h>
 
#define endl '\n'
 
using namespace std;
using ll = long long;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    ll n; cin >> n;
 
    cout << n << ' ';
    
    while(n!=1) {
        if (n%2==0) {
            n /= 2;
        }
        else {
            n = n * 3 + 1;
        }
 
        cout << n << ' ';   
    }
 
    return 0;
}