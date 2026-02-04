/**
 * Author:      Lua
 * Problem:     1636 - Coin Combinations II
 * Link:        https://cses.fi/problemset/task/1636
 * Status:      AC
 * Created:     31-01-2026 15:13:19
 **/

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;
// const int MXN = 1e6+10;

// vector<map<int, int>> dp(MXN);
// int f(int i, int k, vector<int>& arr) {
//     if (dp[i].count(k)) return dp[i][k];
//     if (k == 0) return 1;
//     if(i >= arr.size() || k < 0) return 0;

//     return dp[i][k] = (f(i+1, k, arr) + f(i, k-arr[i], arr)) % MOD;
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x; cin >> n >> x;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    
    vector<int> dp(1e6+1); dp[0] = 1;
    for (int i = 1; i <= n; i++) 
        for (int j = 0; j <= x; j++)
            if (j-arr[i-1] >= 0) 
                dp[j] = (dp[j] + dp[j-arr[i-1]]) % MOD;

    cout << dp[x] << '\n';

    return 0;
}