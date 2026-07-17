/**
 * Author:      Lua
 * Problem:     J
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/103049/problem/J
 * Status:      ~
 * Created:     12-07-2026 09:01:59
 **/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> degree(n, 0);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++, degree[v]++;
    }

    vector<pair<int,int>> roots;
    for (int i = 0; i < n; i++) {
        roots.emplace_back(degree[i], i);
    }

    sort(roots.rbegin(), roots.rend());

    for (int i = 0; i < n; i++) { 
        auto [degreee, root] = roots[i];

        vector<vector<int>> tree(n);
        vector<bool> visited(n, false);
        visited[root] = true;

        auto dfs = [&](auto self, int u, int p) -> void {
            for (auto v : adj[u]) {
                if (v == p) continue;
                if (visited[v]) continue;
                visited[v] = true;
                tree[u].push_back(v);
                self(self, v, u);
            }
        }; dfs(dfs, root, -1);

        vector<int> size(n, 0);

        auto get_size = [&](auto self, int u, int p) -> int {
            int sz = 1;
            for (auto v : tree[u]) {
                if (v == p) continue;
                sz += self(self, v, u);
            }
            return size[u] = sz;
        }; get_size(get_size, root, -1);

        auto subset_sum = bitset<(int)1e5+10>(1); vector<int> path;
        auto dfs_subset = [&](auto self, int u, int p, bitset<(int)1e5+10>& ss, int t, vector<int>& ans) -> bool {
            t += 1;

            if ((n-t) % 2 == 0) {
                if (ss[(n-t)/2] == 1) {
                    ans.push_back(u);
                    return true;
                }
            }

            for (auto v : tree[u]) {
                if (v == p) continue;
                auto copy = make_unique<bitset<(int)1e5+10>>(ss);
                for (auto w : tree[u]) {
                    if (w == v) continue;
                    if (w == p) continue;
                    *copy |= (*copy << size[w]);
                }

                if (self(self, v, u, *copy, t, ans)) {
                    ans.push_back(u);
                    return true;
                }
            }

            return false;
        }; if(!dfs_subset(dfs_subset, root, -1, subset_sum, 0, path)) continue;
        reverse(path.begin(), path.end());

        int mole_size = (n - path.size()) / 2;

        cout << path.size() << ' ' << mole_size << '\n';

        for (auto &x : path) cout << x+1 << ' '; cout << '\n';
        set<int> path_nodes(path.begin(), path.end());
    
        vector<int> mole1, mole2;
        set<int> actives_set;

        for (auto &u : path) {
            for (auto &v : tree[u]) {
                if (!path_nodes.count(v)) actives_set.insert(v);
            }
        }

        vector<int> actives;
        for (auto &x : actives_set) actives.push_back(x);

        int amm = 0;
        auto rec = [&](auto self, int i = 0) -> bool {
            if (amm > mole_size) return false;
            if (i >= actives.size()) return amm == mole_size;
 
            mole1.push_back(actives[i]);
            amm += size[actives[i]];
            if (self(self, i+1)) return true;
            amm -= size[actives[i]];
            mole1.pop_back();
 
            mole2.push_back(actives[i]);
            if (self(self, i+1)) return true;
            mole2.pop_back();
 
            return false;
        }; rec(rec);

        set<int> mole_s1(mole1.begin(), mole1.end());
        set<int> mole_s2(mole2.begin(), mole2.end());

        vector<bool> visited2(n, false);

        auto dfs3 = [&](auto self, int u, int p, set<int>& mole) -> void {
            for (auto v : tree[u]) {
                if (v == p) continue;
                if (visited2[v]) continue;
                visited2[v] = true;
                mole.insert(v);
                self(self, v, u, mole);
            }
        };

        for (auto x : mole1) {
            if (visited2[x]) continue;
            visited2[x] = true;
            mole_s1.insert(x);
            dfs3(dfs3, x, -1, mole_s1);
        }
        for (auto x : mole2) {
            if (visited2[x]) continue;
            visited2[x] = true;
            mole_s2.insert(x);
            dfs3(dfs3, x, -1, mole_s2);
        }
        

        for (auto &x: mole_s1) cout << x+1 << ' '; cout << '\n';
        for (auto &x: mole_s2) cout << x+1 << ' '; cout << '\n';

        return 0;
    }

    assert(1 != 1);
    return 0;
}
