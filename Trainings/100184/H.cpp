/**
 * Author:      Lua
 * Problem:     H
 * Link:        https://codeforces.com/gym/100184/problem/H
 * Status:      ~
 * Created:     16-05-2026 08:41:06
 **/

#include <bits/stdc++.h>

using namespace std;
using iii = tuple<int, int,int>;
using graph = vector<vector<iii>>;

const int MXN = 1e5 + 100;

vector<int> get_sz(MXN, 0);

int get_sz_dfs(int u, int p, graph& adj) {
    int sz = 0;
    for (auto [v, w_v, i]: adj[u]) {
        if (v == p) continue;
        sz += get_sz_dfs(v, u, adj);
    }
    return get_sz[u] = 1 + sz;
}

vector<pair<int, vector<int>>> get_crt(MXN);
pair<int, vector<int>> get_crt_dfs(int u, int p, graph& adj) {
    pair<int, vector<int>> mx = {0, {} };
    for (auto [v, w_v, i]: adj[u]) {
        if (v == p) continue;
        int k_ = get_sz[v] * w_v;

        auto [crt, vec] = get_crt_dfs(v, u, adj);
        if (crt > mx.first) mx = {crt, vec};
        if (crt == mx.first) {
            if (mx.second.size() < vec.size()) swap(vec, mx.second);
            for (auto &x : vec) mx.second.push_back(x);
        }

        if (k_ > mx.first) mx = {k_, {i} };
        if (k_ == mx.first) mx.second.push_back(i);
    }
    return get_crt[u] = mx;
}


vector<pair<int, vector<int>>> memo(MXN);
pair<int, vector<int>> dfs(int u, int p, graph& adj, map<int, vector<int>>& mp, int n) {
    pair<int, vector<int>> ans = get_crt[u];

    if (!mp.empty()) {
        auto [mxv, mxvec] = *(--mp.end());
        if (mxv > ans.first) ans = {mxv, mxvec};
        if (mxv == ans.first) {
            if (ans.second.size() < mxvec.size()) swap(mxvec, ans.second);
            for (auto &x : mxvec) ans.second.push_back(x);
        }
    }

    for (auto [v, w_v, i] : adj[u]) {
        if (v == p) continue;
        
        int k_ = (n - get_sz[v]) * w_v;

        mp[k_].push_back(i);

        auto [crt, vec] = dfs(v, u, adj, mp, n);

        mp[k_].pop_back();

    }

    return memo[u] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    graph adj(n);
    for (int i = 0; i < n-1; i++){
        int u, v, w; cin >> u >> v >> w; u--, v--;
        adj[u].emplace_back(v, w, i);
        adj[v].emplace_back(u, w, i);
    }

    get_sz_dfs(0,-1, adj);
    get_crt_dfs(0, -1, adj);

    map<int, vector<int>> mp;

    dfs(0, -1, adj, mp, n);

    map<int,int> freq;

    for (int i = 0; i < n; i++) {
        sort(memo[i].second.begin(), memo[i].second.end());
        memo[i].second.erase(unique(memo[i].second.begin(), memo[i].second.end()), memo[i].second.end());
        for (auto x : memo[i].second) {
            freq[x]++;
        }
    }

    int mx_freq = 0;

    for (auto [k, v] : freq) {
        if (v > mx_freq) {
            mx_freq = v;
        }
    }
    
    cout << mx_freq << '\n';

    return 0;
}
