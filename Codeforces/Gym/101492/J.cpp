/**
 * Author:      Lua
 * Problem:     J
 * Link:        https://codeforces.com/gym/101492/problem/J
 * Status:      ~
 * Created:     01-05-2026 09:34:33
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n = 100;
    
    vector<ll> dp(n);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n-i; j++)
            dp[i+j] += dp[i];
    }
    
    for (auto &x : dp) cout << x << ' ';
    cout << endl;

    ll ans = 0; int i = 0;
    for (auto&x: dp) {
        cout << (ans += x) << ' ';
        i++;
        if (ans > 1e18) {
            cout << i << endl;
            break;
        }
    }
    cout << endl;
 
    return 0;
}
