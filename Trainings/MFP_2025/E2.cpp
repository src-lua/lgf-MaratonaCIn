/**
 * Author:      Lua
 * Problem:     E
 * Link:        https://codeforces.com/group/9CNwiex6Ir/contest/606592/problem/E
 * Status:      AC
 * Created:     06-04-2026 21:45:52
 **/

#include <bits/stdc++.h>

using namespace std;

struct sat {
	int n, tot;
	vector<vector<int>> g;
	vector<int> vis, comp, id, ans;
	stack<int> s;

	sat() {}
	sat(int n_) : n(n_), tot(n), g(2*n) {}

	int dfs(int i, int& t) {
		int lo = id[i] = t++;
		s.push(i), vis[i] = 2;
		for (int j : g[i]) {
			if (!vis[j]) lo = min(lo, dfs(j, t));
			else if (vis[j] == 2) lo = min(lo, id[j]);
		}
		if (lo == id[i]) while (1) {
			int u = s.top(); s.pop();
			vis[u] = 1, comp[u] = i;
			if ((u>>1) < n and ans[u>>1] == -1) ans[u>>1] = ~u&1;
			if (u == i) break;
		}
		return lo;
	}

	void add_impl(int x, int y) {
		x = x >= 0 ? 2*x : -2*x-1;
		y = y >= 0 ? 2*y : -2*y-1;
		g[x].push_back(y);
		g[y^1].push_back(x^1);
	}

	pair<bool, vector<int>> solve() {
		ans = vector<int>(n, -1);
		int t = 0;
		vis = comp = id = vector<int>(2*tot, 0);
		for (int i = 0; i < 2*tot; i++) if (!vis[i]) dfs(i, t);
		for (int i = 0; i < tot; i++)
			if (comp[2*i] == comp[2*i+1]) return {false, {}};
		return {true, ans};
	}
};

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, m; cin >> n >> m;
    vector<vector<int>> board(n, vector<int>(m));
    for (auto &r : board) for (auto &x : r) cin >> x;
    
    sat Sat(n*m);

    for (int i = 0; i < n; i++) 
    for (int j = 0; j < m; j++) 
    for (int d = 0; d < 4; d++) {
        int x = i + dx[d], y = j + dy[d];
        if (x < 0 || x >= n || y < 0 || y >= m) continue;
        
        if (board[i][j] == board[x][y]) {
            Sat.add_impl(i*m+j, ~(x*m+y));
            Sat.add_impl(~(i*m+j), x*m+y);
        }
        if (board[i][j] == board[x][y] + 1) {
            Sat.add_impl(~(i*m+j), ~(x*m+y));
        }
        if (board[i][j] == board[x][y] - 1) {
            Sat.add_impl(i*m+j, x*m+y);
        }
    }

    Sat.solve();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j] + Sat.ans[i*m+j] << ' ';
        } cout << '\n';
    }

    return 0;
}
