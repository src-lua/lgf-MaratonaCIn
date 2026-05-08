/**
 * Author:      Lua
 * Problem:     I
 * Link:        https://codeforces.com/group/9CNwiex6Ir/contest/530284/problem/I
 * Status:      AC
 * Created:     07-05-2026 19:05:05
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;

    vector<vector<string>> verses;

    cin.get();

    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<string> verse;
        string t;
        while (ss >> t) verse.push_back(t);
        verses.push_back(verse);
    }

    int m; cin >> m;
    map<string, ll> value;
    for (int i = 0; i < m; i++) {
        string s; int x; cin >> s >> x;
        value[s] = x;
    }

    ll ans = 0;
    ll mx_idx = 0, mx = 0;

    for (int i = 0; i < n; i++) {
        ll ths = 0;
        for (auto &s : verses[i]) ths += value[s];
        ans += ths;
        if (ths >= mx) {
            mx = ths;
            mx_idx = i+1;
        }
    }
    

    cout << ans << ' ' << mx_idx << '\n';

    return 0;
}
