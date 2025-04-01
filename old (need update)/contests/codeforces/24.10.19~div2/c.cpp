#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int n; cin >> n;
    string s; cin >> s;

    if (s[0] == '1' || s[s.size()-1] == '1') {
        cout << "YES\n";
        return 0;
    }
    else {
        for (int i = 1; i < n-1; i++) {
            if (s[i] == '1') {
                if (s[i-1] == '0' && s[i+1] == '0') {
                    s[i] = '0';
                }
            }
        }

        for (auto e : s) {
            if (e == '1') {
                cout << "YES\n";
                return 0;
            }
        }
    }

    cout << "NO\n";
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