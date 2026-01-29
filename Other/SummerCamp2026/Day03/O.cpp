/**
 * Author:      Lua
 * Problem:     O
 * Link:        https://vjudge.net/contest/782311#problem/O
 * Status:      AC
 * Created:     29-01-2026 11:15:23
 **/

#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;

struct seg_tree {
    int n;
    vector<int> tree;

    seg_tree(int n) : n(n), tree(2*n) {}

    int merge(int a, int b) {
        return a +b;
    }

    void update(int i, int x) {
        i += n;
        tree[i] = x;
        for (i >>= 1; i > 0; i >>= 1) {
            tree[i] = merge(tree[i << 1], tree[(i << 1) | 1]);
        }
    }

    int query(int i, int j) {
        int l = 0;
        int r = 0;
        for (i += n, j += n + 1; i < j; i >>= 1, j >>= 1) {
            if (i & 1) {
                l = merge(l, tree[i]);
                ++i;
            }
            if (j & 1) {
                --j;
                r = merge(tree[j], r);
            }
        }
        return merge(l, r);
    }
};

void bfs(vector<vector<int>>& adj, vector<int>& visited, vector<int>& dist, int start, int cookie) {
    queue<int> q;
    visited[start] = cookie;
    dist[start] = 0;
    q.push(start);

    while(!q.empty()) {
        auto top = q.front(); q.pop();

        for (auto e : adj[top]) {
            if (visited[e] != -1) continue;
            visited[e] = cookie;
            dist[e] = dist[top] + 1;
            q.push(e);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    
    vector<vector<int>> adj(n+n-1);
    vector<int> degree(n+n-1, 0);

    int turning = 0;

    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        int t = i+n;

        adj[u].push_back(t); adj[t].push_back(u);
        adj[v].push_back(t); adj[t].push_back(v);
        
        degree[u]++, degree[v]++, degree[t]++;

        if (degree[u] > 2) turning = u;
        if (degree[v] > 2) turning = v; 
    }

    

    vector<int> visited(n+n-1, -1);
    vector<int> dist(n+n-1, 0);
    int cookie = 0;
    visited[turning] = cookie++;
    for (auto e : adj[turning]) {
        if (visited[e] == -1) {
            bfs(adj, visited, dist, e, cookie++);
        }
    }

    map<int, pii> translate;
    vector<vector<int>> colors(cookie);

    for (int i = 0; i < n+n-1; i++) {
        translate[i] = {visited[i], dist[i]};
        colors[visited[i]].push_back(0);
    }
    
    vector<seg_tree> segs(cookie, seg_tree(1));
    for (int i = 0; i < cookie; i++) {
        segs[i] = seg_tree(colors[i].size());
        for (int j = 0; j < colors[i].size(); j++) segs[i].update(j, 1);
    }

    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int op; cin >> op;
        if (op == 1) { // paint black
            int u; cin >> u; u += n-1;

            auto [tag, idx] = translate[u];

            segs[tag].update(idx, 1);
        }
        else if (op == 2) { // paint white
            int u; cin >> u; u += n-1;

            auto [tag, idx] = translate[u];

            segs[tag].update(idx, 0);
        }
        else { // query 
            int u, v; cin >> u >> v; u--, v--;

            auto [tag_u, idx_u] = translate[u];
            auto [tag_v, idx_v] = translate[v];

            if (tag_u == tag_v) {
                int tag = tag_u;
                int l = min(idx_u, idx_v), r = max(idx_u, idx_v); 

                cout << (
                    segs[tag].query(l, r-1) == r+1-l-1 ? (r+1-l-1)/2 : -1
                ) << '\n';
            }
            else { // checkar se turning é preto
                if (segs[tag_u].query(0, idx_u) != idx_u+1-0 || 
                    segs[tag_v].query(0, idx_v-1) != idx_v+1-0-1)
                        cout << -1 << '\n';
                else cout << (idx_u+1 + idx_v+1) / 2 << '\n';
                
            }

        }
    }
    
    return 0;
}
