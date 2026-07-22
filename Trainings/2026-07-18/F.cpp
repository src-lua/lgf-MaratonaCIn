/**
 * Author:      Lua
 * Problem:     F
 * Link:        https://codeforces.com/group/btcK4I5D5f/contest/701070/problem/F
 * Status:      AC
 * Tags:        
 * Created:     18-07-2026 08:31:07
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MXN = 1e6+5;

auto dp = vector<vector<ll>>(MXN, vector<ll>(2, -1));
ll solve(int i, bool selling, vector<ll>& arr) {
    if (i >= arr.size()) return 0;
    if (dp[i][selling] != -1) return dp[i][selling];

    if (selling) return dp[i][selling] = max(
        solve(i+1, selling, arr),
        arr[i] + solve(i+1, !selling, arr)
    );

    return dp[i][selling] = max (
        solve(i+1, selling, arr),
        - arr[i] + solve(i+1, !selling, arr)
    );
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<ll> arr(n); for (auto &x : arr) cin >> x;

    cout << solve(0, false, arr) << '\n';
    
    return 0;
}
