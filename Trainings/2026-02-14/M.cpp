/**
 * Author:      Lua
 * Problem:     M - Two Operations
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/102263/problem/M
 * Status:      AC
 * Created:     14-02-2026 13:45:39
 **/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s; cin >> s;
    map<char, int> m;
    for (auto const &c : s) m[c]++;

    for (auto &[k, v] : m) {
        if (k == 'z') break;
        m[k+1] += v/2; v %= 2;
    }

    string ans;
    for (auto const &[k, v] : m)
        for (int i = 0; i < v; i++) ans.push_back(k);

    reverse(ans.begin(), ans.end());

    cout << ans << '\n';

    return 0;
}
