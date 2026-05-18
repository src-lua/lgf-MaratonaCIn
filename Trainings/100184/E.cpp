/**
 * Author:      Lua
 * Problem:     E
 * Link:        https://codeforces.com/gym/100184/problem/E
 * Status:      ~
 * Created:     16-05-2026 08:41:06
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve(int i, vector<ll>& arr, vector<ll>& memo) {
    if (i + 1 >= arr.size()) return 0;
    if (memo[i] != -1) return memo[i];

    return memo[i] = max({
        solve(i+1, arr, memo),
        arr[i] + arr[i+1] + solve(i+2, arr, memo)
    });
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    vector<int> arr(n); for (auto &x : arr) cin >> x;
    vector<vector<ll>> lines(m);
    for (int i = 0; i < m; i++) 
        for (int j = i; j < n; j+=m) 
            lines[i].push_back(arr[j]);

    ll ans = 0;
    for (int i = 0; i < m; i++) {
        vector<ll> memo(lines[i].size(), -1);
        ans += solve(0, lines[i], memo);
    }

    cout << ans << '\n';

    return 0;
}
