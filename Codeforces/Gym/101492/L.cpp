/**
 * Author:      Lua
 * Problem:     L
 * Link:        https://codeforces.com/gym/101492/problem/L
 * Status:      ~
 * Created:     01-05-2026 09:34:33
 **/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int m, n, k; cin >> m >> n >> k;

    string s, t; cin >> s >> t;
    t += m * '&';

    for (int i = 0; i < n; i++) {
        int mismatch = 0;
        for (int j = 0; j < m; j++) {
            if (t[i] != s[j]) mismatch++;
            if (mismatch > k) break;
        }
        if (mismatch <= k) {
            cout << "S\n";
            return 0;
        }
    }


    abcdef
    
    cout << "N\n";
    return 0;
}
