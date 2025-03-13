#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int n; cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (j == 0 || j == i-1) cout << 1 << ' ';
            else cout << 0 << ' ';
        }
        cout << endl;
    }
    

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}