#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

void solve() {
    ull n; cin >> n;

    ull ans = 0;
    ull low = 1;
    for (int d = 1; d <= 19; d++) {
        ull high = low * 10 - 1;       
        if (d % 2 == 1 && n >= low) {
            ans += min(n, high) - low + 1;
        }
        low *= 10;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) solve();    

    return 0;
}