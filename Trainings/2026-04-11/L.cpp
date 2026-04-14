/**
 * Author:      Lua
 * Problem:     L
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/103940/problem/L
 * Status:      AC
 * Created:     13-04-2026 21:23:46
 **/

#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e6+10;
const int MOD = 1e9+7;

// o somatorio dos primeiros cara tem que ser maior que o prox elemento
// Arr[0] = 1 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<int> dp(MXN, 0);
    vector<int> prefix(MXN+1, 0);

    dp[1] = 1, dp[2] = 1;
    prefix[0] = 0, prefix[1] = 1, prefix[2] = 2;

    for (int i = 3; i < MXN; i++) {
        dp[i] = ((prefix[i-1] - prefix[(i-1)/2]) % MOD + MOD) % MOD;
        prefix[i] = (prefix[i-1] + dp[i]) % MOD;
    }

    int n; cin >> n;
    cout << dp[n] << endl;

    return 0;
}
