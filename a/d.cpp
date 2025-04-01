#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int n, m; cin >> n >> m;
    int k = int(m/8)*8;

    int l = ((k^n)/8)*8;
    set<int> s;
    for (int i = l; i < l+8; i++) {
        s.insert(i);
    }

    for (int i = k; i < m+1; i++) {
        s.erase(i^n);
    }


    cout << *s.begin() << endl;

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