/**
 * Author:      Lua
 * Problem:     F
 * Link:        https://codeforces.com/group/9CNwiex6Ir/contest/606592/problem/F
 * Status:      AC
 * Created:     06-04-2026 21:45:52
 **/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, p, k; cin >> n >> p >> k; p--;

    int ans = (p+k) % (n-1);
    if (ans >= p) ans++;

    cout << ans + 1 << '\n';

    return 0;
}
