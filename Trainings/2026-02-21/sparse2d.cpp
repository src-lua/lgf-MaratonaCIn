struct NodeMinMax {
    int mn, mx;
    
    NodeMinMax(int mn = 2e9, int mx = -2e9) : mn(mn), mx(mx) {}
    
    static inline NodeMinMax merge(const NodeMinMax& l, const NodeMinMax& r) {
        return NodeMinMax(
            min(l.mn, r.mn),
            max(l.mx, r.mx)
        );
    }
};

template<typename NODE>
struct SparseTable2D {
    int N, M, K_N, K_M;
    vector<NODE> st;
    vector<int> lg;

    inline int idx(int kr, int kc, int r, int c) const {
        return kr * ((K_M + 1) * N * M) + kc * (N * M) + r * M + c;
    }

    template<typename T>
    SparseTable2D(const vector<vector<T>>& v) {
        N = v.size();
        M = (N > 0) ? v[0].size() : 0;
        
        K_N = (N > 0) ? __lg(N) : 0;
        K_M = (M > 0) ? __lg(M) : 0;
        
        int max_dim = max(N, M);
        lg.assign(max_dim + 1, 0);
        for (int i = 2; i <= max_dim; i++) lg[i] = lg[i / 2] + 1;
        
        st.assign((K_N + 1) * (K_M + 1) * N * M, NODE());

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                st[idx(0, 0, i, j)] = NODE(v[i][j], v[i][j]);
            }
        }

        for (int kr = 0; kr <= K_N; kr++) {
            for (int kc = 0; kc <= K_M; kc++) {
                if (kr == 0 && kc == 0) continue;
                
                for (int i = 0; i + (1 << kr) <= N; i++) {
                    for (int j = 0; j + (1 << kc) <= M; j++) {
                        if (kr != 0) {
                            st[idx(kr, kc, i, j)] = NODE::merge(
                                st[idx(kr - 1, kc, i, j)],
                                st[idx(kr - 1, kc, i + (1 << (kr - 1)), j)]
                            );
                        } else {
                            st[idx(kr, kc, i, j)] = NODE::merge(
                                st[idx(kr, kc - 1, i, j)],
                                st[idx(kr, kc - 1, i, j + (1 << (kc - 1)))]
                            );
                        }
                    }
                }
            }
        }
    }

    NODE query(int r1, int c1, int r2, int c2) {
        int kr = lg[r2 - r1 + 1];
        int kc = lg[c2 - c1 + 1];
        
        NODE tl = st[idx(kr, kc, r1, c1)];
        NODE tr = st[idx(kr, kc, r1, c2 - (1 << kc) + 1)];
        NODE bl = st[idx(kr, kc, r2 - (1 << kr) + 1, c1)];
        NODE br = st[idx(kr, kc, r2 - (1 << kr) + 1, c2 - (1 << kc) + 1)];
        
        return NODE::merge(
            NODE::merge(tl, tr),
            NODE::merge(bl, br)
        );
    }
};













/**
 * Author:      Lua
 * Problem:     L - Eyb0ss
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/101915/problem/L
 * Status:      ~
 * Created:     21-02-2026 08:03:55
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

void solve(){
    int n; cin >> n;
    vector<vector<int>> board(n, vector<int>(n));
    for (auto &row : board) for (auto &x: row) cin >> x;

    SparseTable2D<NodeMinMax> st(board);

    ll ans = 0;

    for (int r1 =  0; r1 < n; r1++) for (int c1 =  0; c1 < n; c1++) 
    for (int r2 = r1; r2 < n; r2++) for (int c2 = c1; c2 < n; c2++) 
        ans += st.query(r1, c1, r2, c2).mx - st.query(r1, c1, r2, c2).mn;
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tc; cin >> tc; while(tc--) solve();

    return 0;
}
