/**
 * Author:      Lua
 * Problem:     H
 * Link:        https://vjudge.net/contest/783195#problem/H
 * Status:      ~
 * Created:     30-01-2026 20:41:29
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, budget; cin >> n >> budget;

    vector<pii> arr(n);

    for (auto &[x, _] : arr) cin >> x;
    for (auto &[_, x] : arr) cin >> x;

    /* inverter a dp
        Qual o máximo de itens eu compro com X dinheiro 
                        ->
        Qual o mínimo de dinheiro eu gasto para comprar K itens
    */

    sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
        return a.second < b.second;
    });

    const ll inf = 1e18;

    vector<vector<ll>> dp(n+1, vector<ll>(1e3, inf));
    dp[n][0] = 0;

    for (int i = n - 1; i >= 0; i++) {
        for (int j = 0; j <= i; j++) {
            // pegar o item i
            dp[i-1][j+1] = min(dp[i][j], dp[i][j+1]);
        }
    }

    int ans = 0;
    for (int j = 0; j <= n; j++) {
        if (dp[n][j] <= budget) ans = j;
    }
    cout << ans << endl;

    return 0;
}