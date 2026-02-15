/**
 * Author:      Lua
 * Problem:     C - Lunch Break
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/101498/problem/C
 * Status:      AC
 * Created:     07-02-2026 08:44:50
 **/

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, c; cin >> a >> b >> c;

    if (a < b && a < c) cout << "First\n";
    else if (b < a && b < c) cout << "Second\n";
    else if (c < a && c < b) cout << "Third\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tc; cin >> tc; while (tc--) solve();

    return 0;
}
