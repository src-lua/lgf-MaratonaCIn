/**
 * Author:      Lua
 * Problem:     B - Road to Arabella
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/102263/problem/B
 * Status:      AC
 * Created:     14-02-2026 13:45:39
 **/

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;

    cout << (n%2 || n - k > 1 ? "Kilani\n" : "Ayoub\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tc; cin >> tc; while(tc--) solve();

    return 0;
}
