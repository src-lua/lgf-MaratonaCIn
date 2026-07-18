/*
Lucas Guimarães Fernandes </lgf_cin>
MaratonaCIn @ CIn - UFPE

[Far Far Away](https://codeforces.com/gym/105741/problem/F)
Rating: NOT DEFINED
Tags: Tree; DFS; Graph;

Date: 2025-04-01
Status: Upsolved
*/

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int n; 
string s;

void dfs_populate(int u, int p, vector<vector<int>>& adj, vector<int>& food, vector<int>& end) {
    food[u] = s[u] - '0';
    end[u] = (u == n-1 ? 1 : 2);
    for (int v : adj[u]) {
        if (v == p) continue;

        dfs_populate(v, u, adj, food, end);

        food[u] += food[v];
        end[u] = min(end[v], end[u]);
    }
}

int dfs_calc(int u, int p, vector<vector<int>>& adj, vector<int>& food, vector<int>& end) {
    int answ = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (food[v] == 0) continue;

        answ += end[v] + dfs_calc(v, u, adj, food, end);
    }
    return answ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    cin >> s;
    s[n-1] = '1';

    vector<vector<int>> adj(n);
    int a, b;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    vector<int> food(n), end(n);
    dfs_populate(0, -1, adj, food, end);
    cout << dfs_calc(0, -1, adj, food, end) << endl;

    return 0;
}