/**
 * Author:      Lua
 * Problem:     B - Frog 2
 * Link:        https://atcoder.jp/contests/dp/tasks/dp_b
 * Status:      AC
 * Created:     31-01-2026 14:43:41
 **/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;

    vector<int> dp(n, INT_MAX);
    dp[n-1] = 0;

    for (int i = n - 1; i >= 0; i--)
        for (int j = 1; j <= k; j++) 
            if (i+j < n) dp[i] = min(dp[i], dp[i+j] + abs(arr[i+j] - arr[i]));
            
    cout << dp[0] << endl;

    return 0;
}