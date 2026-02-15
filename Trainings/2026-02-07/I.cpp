/**
 * Author:      Lua
 * Problem:     I - Rock Piles
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/101498/problem/I
 * Status:      AC
 * Created:     07-02-2026 08:44:50
 **/

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b; cin >> a >> b;

    cout << ((a % 2 || b % 2) ? "hasan\n" : "abdullah\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tc; cin >> tc; while (tc--) solve();

    return 0;
}
