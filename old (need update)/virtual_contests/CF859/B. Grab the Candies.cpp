#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int n; cin >> n;
    int odd = 0;
    int even = 0;

    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x % 2 == 0) even += x;
        else odd += x;
    }
    
    if (even > odd) cout << "YES\n";
    else cout << "NO\n";

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