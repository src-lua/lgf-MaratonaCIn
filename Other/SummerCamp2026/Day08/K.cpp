/**
 * Author:      Lua
 * Problem:     K
 * Link:        https://vjudge.net/contest/784977#problem/K
 * Status:      AC
 * Created:     28-01-2026 16:28:16
 **/

#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s; cin >> s;
    s = "00" + s;
    int n = s.size();
    set<int> ans;

    if ((s.back()-'0') % 2 == 0) ans.insert(2);
    if (s.back() == '0' || s.back() == '5') ans.insert(5);

    int digit_sum = 0;
    for (int i = 0; i < n; i++) digit_sum = (digit_sum + (s[i]-'0')) % 3;
    if (digit_sum % 3 == 0) ans.insert(3);

    if (ans.count(2) && ans.count(3)) ans.insert(6);

    if (stoi(s.substr(n-2, 2)) % 4 == 0) ans.insert(4);

    if (ans.empty()) cout << "-1\n";
    else {
        cout << *ans.begin();
        ans.erase(begin(ans));
        for (auto e : ans) cout << " " << e; 
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tc; cin >> tc; while(tc--) solve();

    return 0;
}