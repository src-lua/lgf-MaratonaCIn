/**
 * Author:      Lua
 * Problem:     A - Watching TV
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/101498/problem/A
 * Status:      AC
 * Created:     07-02-2026 08:44:50
 **/

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    map<int,int> freq;

    for (int i = 0; i < n; i++) {
        string s; int f; cin >> s >> f;
    
        freq[f]++;
    }

    int mx = 0;
    int mx_f = -1;
    for (auto [f, c] : freq) {
        if (c > mx) {
            mx = c;
            mx_f = f;
        }
    }

    cout << mx_f << endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tc; cin >> tc; while(tc--) solve();

    return 0;
}
