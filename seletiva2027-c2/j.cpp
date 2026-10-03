#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    const int AVAILABLE = 4 * 60;

    int n, k; cin >> n >> k;

    int remaining = AVAILABLE - k;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        remaining -= 5*i;
        if (remaining >= 0) ans = i;
        else break;
    }
    
    cout << ans << '\n';

    return 0;
}