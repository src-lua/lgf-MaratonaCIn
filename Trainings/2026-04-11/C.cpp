/**
 * Author:      Lua
 * Problem:     C
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/103940/problem/C
 * Status:      AC
 * Created:     13-04-2026 21:23:46
 **/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;

    unordered_map<int, vector<int>> asked, got;
    vector<int> ids;

    for (int i = 0; i < n; i++) {
        int id, q; cin >> id >> q;
        ids.push_back(id);
        asked[id].resize(q);
        for (auto &x : asked[id]) cin >> x;
    }

    for (int i = 0; i < m; i++) {
        int id, q; cin >> id >> q;
        ids.push_back(id);
        got[id].resize(q);
        for (auto &x : got[id]) cin >> x;
    }

    sort(ids.begin(), ids.end());
    ids.erase(unique(ids.begin(), ids.end()), ids.end());

    int extra = 0, missed = 0;
    vector<pair<int, vector<pair<int,char>>>> ans;

    for (auto id : ids) {
        auto &a = asked[id];
        auto &g = got[id];
        vector<pair<int,char>> errs;

        for (auto x : a) if (find(g.begin(), g.end(), x) == g.end())
            errs.push_back({x, '+'}), missed++; 

        for (auto x : g) if (find(a.begin(), a.end(), x) == a.end())
            errs.push_back({x, '-'}), extra++;

        if (!errs.empty()) {
            sort(errs.begin(), errs.end());
            ans.push_back({id, move(errs)});
        }
    }

    if (ans.empty()) {
        cout << "GREAT WORK! NO MISTAKES FOUND!\n";
        return 0;
    }

    for (auto &[id, errs] : ans) {
        cout << id;
        for (auto &[x, c] : errs) cout << ' ' << c << x;
        cout << '\n';
    }

    cout << "MISTAKES IN " << ans.size() << " STUDENTS: "
         << extra << " NOT REQUESTED, " << missed << " MISSED\n";

    return 0;
}
