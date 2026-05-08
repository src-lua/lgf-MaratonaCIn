/**
 * Author:      Lua
 * Problem:     G
 * Link:        https://codeforces.com/group/9CNwiex6Ir/contest/530284/problem/G
 * Status:      AC
 * Created:     07-05-2026 19:05:05
 **/

#include <bits/stdc++.h>

using namespace std;

const int MXN = 1500+100;
const int MOD = 1e9+7;

vector<vector<int>> dp(MXN, vector<int>(MXN, -1));
int solve(int idx, int curr, int target, vector<int>& arr) {
    if (curr >= target) return 1;
    if (idx >= arr.size()) return 0;
    if (dp[idx][curr] != -1) return dp[idx][curr];

    return dp[idx][curr] = (
        solve(idx+1, curr, target, arr) +
        (curr >= arr[idx] ? solve(idx+1, curr+arr[idx], target, arr) : 0) 
        
    ) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, x; cin >> n >> x;
    vector<int> arr(n); for (auto &k : arr) cin >> k;
    sort(arr.begin()+1, arr.end());

    cout << solve(1, arr[0],x,arr) << '\n';

    return 0;
}   
