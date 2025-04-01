#include <bits/stdc++.h>
 
#define ll long long
// #define int long long
 
using namespace std;
 
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    ll n; cin >> n;
 
    ll sum = (1+n)*n/2;
 
    if (sum%2 != 0 ) {
        cout << "NO";
        return 0;
    }
 
    sum /= 2;
    
    vector<int> set1;
    vector<int> set2;
 
    ll sum1 = 0;
 
    for (ll i = n; i >= 1; i--) {
        if (i+sum1 <= sum) {
            set1.push_back(i);
            sum1 += i;
        }
        else {
            set2.push_back(i);
        }
    }
 
    cout << "YES" << '\n';
    cout << set1.size() << '\n';
    for (auto e: set1) cout << e << ' ';
    cout << '\n' << set2.size() << '\n'; 
    for (auto e: set2) cout << e << ' ';
 
    return 0;
}