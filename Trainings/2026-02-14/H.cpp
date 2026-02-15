/**
 * Author:      Lua
 * Problem:     H - Steaks
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/102263/problem/H
 * Status:      AC
 * Created:     14-02-2026 13:45:39
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n, k; cin >> n >> k;
    if (k >= n) cout << 10 << '\n';
    else cout << (n+k-1)/(k) * 5LL << '\n';

    return 0;
}