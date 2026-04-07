/**
 * Author:      Lua
 * Problem:     C
 * Link:        https://codeforces.com/group/9CNwiex6Ir/contest/606592/problem/C
 * Status:      AC
 * Created:     06-04-2026 21:45:52
 **/

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, c; cin >> a >> b >> c;

    if (a == b) cout << c << '\n'; else
    if (a == c) cout << b << '\n'; else
    if (b == c) cout << a << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tc; cin >> tc; while(tc--) solve();

    return 0;
}
