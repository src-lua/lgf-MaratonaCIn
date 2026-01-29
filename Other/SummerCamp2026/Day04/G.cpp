/**
 * Author:      Lua
 * Problem:     G
 * Link:        https://vjudge.net/contest/783478#problem/G
 * Status:      WA
 * Created:     29-01-2026 11:21:13
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    vector<ll> dp(1e6+10);
    dp[2] = 1, dp[4] = 2;

    for (int i = 6; i < 1e6+10; i+=2)
        dp[i] = ((((dp[i-2]*3) % MOD) - dp[i-4]) + MOD) % MOD;
    
    
    int n; cin >> n; cout << dp[n] << '\n';
    
    return 0;
}