/**
 * Author:      Lua
 * Problem:     C - Sasha and Array
 * Link:        https://codeforces.com/contest/718/problem/C
 * Status:      ~
 * Created:     29-01-2026 13:41:52
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

const int MOD = 1e9+7;

struct Matrix {
    ll mat[2][2];

    Matrix(initializer_list<initializer_list<ll>> rows) {
        int i = 0; for (auto row : rows) {
            int j = 0; if (i >= 2) break;
            for (auto val : row) {
                if (j >= 2) break;
                mat[i][j] = val;
                j++;
            }
            i++;
        }
    }

    Matrix() { mat[0][0] = mat[0][1] = mat[1][0] = mat[1][1] = 0; }
};

Matrix product(const Matrix &a, const Matrix &b) {
    Matrix c;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                c.mat[i][j] = (c.mat[i][j] + a.mat[i][k] * b.mat[k][j]) % MOD;
            }
        }
    }
    return c;
}

Matrix pow(Matrix b, ll e) {
    Matrix a;
    a.mat[0][0] = 1; a.mat[1][1] = 1;

    if (e == -1) return { {0,1}, {1,-1} };

    while (e > 0) {
        if (e & 1) a = product(a, b);
        b = product(b, b);
        e >>= 1;
    }
    return a;
}

const Matrix fib = { {1,1}, {1,0} };

struct Tag {
    ll x, y, z, w;
    Tag(ll x, ll y, ll z, ll w) : x(x), y(y), z(z), w(w) {}
    Tag() : x(1), y(0), z(0), w(1) {};
    Tag(ll k) {
        auto mat = pow(fib,k);

        x = mat.mat[0][0], y = mat.mat[0][1], z = mat.mat[1][0], w = mat.mat[1][1];
    }

    void compose(const Tag& t) {
        auto t_x = x, t_y = y, t_z = z, t_w = w;

        x = (t_x * t.x + t_y * t.z) % MOD;
        y = (t_x * t.y + t_y * t.w) % MOD;
        z = (t_z * t.x + t_w * t.z) % MOD;
        w = (t_z * t.y + t_w * t.w) % MOD;
    }
};

struct Node {
    ll a, b;

    Node(ll f) {
        Matrix fib = { {1,1}, {1,0} };
        auto mat = pow(fib, f);

        a = mat.mat[0][0], b = mat.mat[0][1];
    }

    Node (ll a, ll b) : a(a), b(b) {};
    Node () : a(0), b(0) {};
    

    static Node neutral() { return Node(); }

    static Node merge(const Node& l, const Node& r) {
        return Node((l.a + r.a) % MOD, (l.b + r.b) % MOD);
    }

    void apply(const Tag& t, int l, int r) {
        auto c = a;
        a = ((a*t.x)%MOD + (b*t.z)%MOD) % MOD;
        b = ((c*t.y)%MOD + (b*t.w)%MOD) % MOD;
    }
};

template<typename NODE, typename TAG>
struct SegTree {
    int N;
    vector<NODE> seg;
    vector<TAG> lazy;

    SegTree(const vector<int>& v) : N(v.size()) {
        seg.resize(4 * N);
        lazy.resize(4 * N);
        build(1, 0, N - 1, v);
    }

    void build(int no, int l, int r, const vector<int>& v) {
        if (l == r) {
            seg[no] = NODE(v[l]); 
            return;
        }
        int m = (l + r) >> 1;
        build(no << 1, l, m, v);
        build((no << 1) | 1, m + 1, r, v);
        seg[no] = NODE::merge(seg[no << 1], seg[(no << 1) | 1]);
    }

    void push(int no, int l, int r) {
        int m = (l + r) >> 1;
        int e = no << 1, d = e | 1;

        seg[e].apply(lazy[no], l, m);
        seg[d].apply(lazy[no], m + 1, r);

        lazy[e].compose(lazy[no]);
        lazy[d].compose(lazy[no]);

        lazy[no] = TAG(); 
    }

    void update(int no, int l, int r, int a, int b, const TAG& v) {
        if (b < l || r < a) return;
        if (a <= l && r <= b) {
            seg[no].apply(v, l, r);
            lazy[no].compose(v);
            return;
        }
        push(no, l, r);
        int m = (l + r) >> 1;
        update(no << 1, l, m, a, b, v);
        update((no << 1) | 1, m + 1, r, a, b, v);
        seg[no] = NODE::merge(seg[no << 1], seg[(no << 1) | 1]);
    }

    NODE query(int no, int l, int r, int a, int b) {
        if (b < l || r < a) return NODE::neutral();
        if (a <= l && r <= b) return seg[no];
        push(no, l, r);
        int m = (l + r) >> 1;
        return NODE::merge(query(no << 1, l, m, a, b),
                           query((no << 1) | 1, m + 1, r, a, b));
    }

    void update(int l, int r, TAG v) { update(1, 0, N - 1, l, r, v); }
    NODE query(int l, int r) { return query(1, 0, N - 1, l, r)  ; }
};

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    for (auto &x : arr) x-=2;

    SegTree<Node, Tag> seg(arr);

    for (int i = 0; i < m; i++) {
        int op; cin >> op;

            if (op == 1) {
            int l, r, x; cin >> l >> r >> x; l--, r--;

            seg.update(l, r, {x});
        }

        else if (op == 2) {
            int l, r; cin >> l >> r; l--, r--;

            auto [a, b] = seg.query(l, r);
            cout << (a + b) % MOD << '\n';
        }
    }
    

    return 0;
}