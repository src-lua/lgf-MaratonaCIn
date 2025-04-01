#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int f (vector<int>& arr, int i, int target, vector<vector<vector<int>>>& dp, int n = 0, int k = 0) {
    if (dp[i][n][k] != -1) return dp[i][n][k];
    if (n == target) return dp[i][n][k] = 0;
    if (i == arr.size()) return dp[i][n][k] = 1e9;
    if (arr[i] == i-k+1) return dp[i][n][k] = f(arr, i+1, target, dp, n+1, k);
    return dp[i][n][k] = min(
        f(arr, i+1, target, dp, n, k),
        f(arr, i+1, target, dp, n, k+1)+1
    );
}

int solve() {

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<vector<vector<int>>> dp(2001, vector<vector<int>>(2001, vector<int>(2001, -1)));
    long long int answ = f(arr, 0, k, dp);
    answ >= 1e9 ? cout << -1 << endl: cout << answ << endl;

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}