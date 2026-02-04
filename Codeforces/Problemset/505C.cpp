/**
 * Author:      Lua
 * Problem:     C - Mr. Kitayuta, the Treasure Hunter
 * Link:        https://codeforces.com/contest/505/problem/C
 * Status:      ~
 * Created:     31-01-2026 15:35:05
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MXN = 3e4+10;
const int MXM = 1e8/MXN;

int offset;

vector<vector<ll>> dp(MXN, vector<ll>(MXM, -1));
ll f(int i, int d, vector<int>& arr) {
    if (dp[i][d + offset] != -1) return dp[i][d  + offset];
    if (i >= arr.size()) return 0;

    return dp[i][d  + offset] = arr[i] + max({
        f(i+d, d, arr),
        f(i+d+1, d+1, arr),
        f(i+d-1, d-1, arr)
    });
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, d; cin >> n >> d;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;

    offset = MXM/2-d;

    cout << f(d, d, arr) << '\n';

    return 0;
}