#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int uniform(ll l, ll r) {
	uniform_int_distribution<ll> uid(l, r);
	return uid(rng);
}

const int MOD = 1e9 + 7;
const int H = 13;
const int P = uniform(1, MOD-1);
const int P2 = uniform(1, MOD-1);

struct tree {
	int fn;
	vector<vector<int>> g;

	tree(int n_) : fn(n_), g(n_) {}

	int subtree_hash(int v, int p) {
		int h = H;
		for (int u : g[v]) if (u != p) {
			h = ll(h) * (P + subtree_hash(u, v)) %  MOD;
		}
		return h;
	}
    // SUBSTITUIR CENTROID PELO ROOT
	int tree_hash(int v=0) {
		return subtree_hash(v, -1);
	}
};

int solve() {
    int n; cin >> n;
    tree T1(n);
    tree T2(n);

    int x, y;
    for (int i = 0; i < n-1; i++) {
        cin >> x >> y; 
        x--, y--;
        if (x == 0 || y == 0) T1.g[0].push_back(0);

        T1.g[x].push_back(y);
        T1.g[y].push_back(x);
    }
    for (int i = 0; i < n-1; i++) {
        cin >> x >> y;
        x--, y--;
        if (x == 0 || y == 0) T2.g[0].push_back(0);

        T2.g[x].push_back(y);
        T2.g[y].push_back(x);
    }

    if (T1.tree_hash(0) == T2.tree_hash(0)) cout << "YES\n";
    else cout <<"NO\n";

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}