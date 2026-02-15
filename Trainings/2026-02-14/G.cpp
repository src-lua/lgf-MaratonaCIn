/**
 * Author:      Lua
 * Problem:     G - Card Game
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/102263/problem/G
 * Status:      AC
 * Created:     14-02-2026 13:45:39
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = double;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cout << setprecision(10) << fixed;

    ll n; cin >> n;

    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        ans += i * (i+1);
    }

    cout << ld(ans)/ld(n);

    return 0;
}
