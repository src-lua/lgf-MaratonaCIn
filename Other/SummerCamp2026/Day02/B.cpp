/**
 * Author:      Lua
 * Problem:     B
 * Link:        https://vjudge.net/contest/782309#problem/B
 * Status:      AC
 * Created:     29-01-2026 11:06:02
 **/

#include <bits/stdc++.h>
#define endl '\n'
using ll = long long;
using namespace std;
vector<vector<int>> gf;
vector<bool> vis;
void dfs(int u) {
    vis[u] = true;
    for (int v : gf[u]) {
        if (!vis[v]) dfs(v);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("in", w);
    int t;
    cin >> t;
    while (t--) {
        char lt;
        cin >> lt;
        int n = lt - 'A';
        n++;
        gf.clear();
        gf.resize(n);
        vis.clear();
        vis.resize(n);
        string s;
        cin.ignore();
        while (getline(cin, s)) {
            if (s.empty()) break;
            int u = s[0] - 'A', v = s[1] - 'A';
            gf[u].push_back(v);
            gf[v].push_back(u);
        }
        int resp = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i);
                resp++;
            }
        }
        cout << resp << "\n";
        if (t) cout << "\n";
    }
}