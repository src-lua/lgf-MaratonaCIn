/**
 * Author:      Lua
 * Problem:     G - Growling Gears
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/101512/problem/G
 * Status:      AC
 * Created:     21-03-2026 09:04:56
 **/

#include <bits/stdc++.h>

using namespace std;
using ld = double;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // y == ax² + bx + c
    // dx/dy == 2*a*x+b

    // 2*a*x+b == 0 (vértice)
    // 2*a*x == -b
    // Xv = -b/2a
    // Yv = a(-b/2a)² + b(-b/2a) + c
    // Yv = b²a/4a² -b²/2a + c
    // Yv = b²/4a -2b²/4a + c

    // Yv = -b²/4a + c
    int tc; cin >> tc; while(tc--) {
        int n; cin >> n;
        pair<ld,int> ans = {0, 0};
        for (int i = 1; i <= n; i++) {
            int a, b, c; cin >> a >> b >> c;
            ans = max(ans, {ld(b*b)/ld(4*a) + ld(c), i});
        }
        cout << ans.second << '\n';
    }

    return 0;
}
