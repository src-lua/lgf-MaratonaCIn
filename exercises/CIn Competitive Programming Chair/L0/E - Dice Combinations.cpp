#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

const int MOD = 1e9+7;

vector<int> dp(10e6, -1);

int solve(int n) {
    if (dp[n] != -1) return dp[n];

    ll answ = 0;

    if (n >= 6) {
        answ = (answ + solve(n-6)) % MOD; 
    }

    if (n >= 5) {
        answ = (answ + solve(n-5)) % MOD; 
    }

    if (n >= 4) {
        answ = (answ + solve(n-4)) % MOD; 
    }

    if (n >= 3) {
        answ = (answ + solve(n-3)) % MOD; 
    }

    if (n >= 2) {
        answ = (answ + solve(n-2)) % MOD; 
    }

    if (n >= 1) {
        answ = (answ + solve(n-1)) % MOD; 
    }

    return dp[n] = answ % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    dp[0] = 1;

    int n; cin >> n;

    cout << solve(n) << endl;

    return 0;
}