#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

const int MXN = 3005;

ll n;
vector<ll> arr(MXN);

vector<vector<ll>> dp(MXN, vector<ll>(MXN));
vector<vector<bool>> dp_bool(MXN, vector<bool>(MXN, false));
ll solve(ll jmp, ll sqr) {
    if (dp_bool[jmp][sqr] != false) return dp[jmp][sqr];
    if (sqr == 1) {
        dp_bool[jmp][sqr] = true;
        return dp[jmp][sqr] = arr[1];
    }
    if (sqr-jmp <= 0) {
        dp_bool[jmp][sqr] = true;
        return dp[jmp][sqr] = 0;
    }

    ll answ = LLONG_MIN;

    for (int i = jmp; i < n; i++) {
        if (sqr-i <= 0) break;
        answ = max(answ, solve(i, sqr-i));
    }

    dp_bool[jmp][sqr] = true;
    return dp[jmp][sqr] = arr[sqr] + answ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    cout << solve(1, n) << endl;
    
    return 0;
}