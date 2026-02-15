/**
 * Author:      Lua
 * Problem:     B - Longest Prefix
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/101498/problem/B
 * Status:      AC
 * Created:     07-02-2026 08:44:50
 **/

#include <bits/stdc++.h>

using namespace std;

void solve() {
    string a, b; cin >> a >> b;
    map<char, int> freq;

    for (auto c : b) freq[c]++;
    int ans = 0;

    for (size_t i = 0; i < a.size(); i++) {
        if (freq[a[i]]--) ans++;
        else break;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tc; cin >> tc; while(tc--) solve();

    return 0;
}
