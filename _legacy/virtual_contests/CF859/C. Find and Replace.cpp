#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int n; cin >> n;
    string s; cin >> s;

    map<int, int> m;

    for (int i = 0; i < n; i++) {
        if (m.count(s[i]) == 0) {
            m[s[i]] = i%2;
        } else{
            if (m[s[i]] != i%2) {
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n";
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