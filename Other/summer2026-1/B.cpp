/**
 * Author:      Lua
 * Problem:     B
 * Link:        https://vjudge.net/contest/781528#problem/B
 * Status:      AC
 * Created:     28-01-2026 16:15:44
 **/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template <typename T>
struct SegTree {
    vector<T> seg;
    vector<T> lazy;
    int N;
    T IDENTITY = INT_MAX;

    SegTree(int n) : N(n) { seg.assign(4 * N, IDENTITY), lazy.assign(4 * N, IDENTITY); }
    SegTree(vector<T>& arr) : N(arr.size()) {
        seg.assign(4 * N, IDENTITY), lazy.assign(4 * N, 0);
        build(1, 0, N - 1, arr);
    }

    T join(T lv, T rv) { return min(lv, rv); }

    void unlazy(int no, int l, int r) {
        if (lazy[no] == 0) return;
        int m = (l + r) / 2, e = no * 2, d = e + 1;

        seg[no] += lazy[no];
        if (l != r) lazy[e] += lazy[no], lazy[d] += lazy[no];
        lazy[no] = 0;
    }

    T query(int no, int l, int r, int a, int b) {
        unlazy(no, l, r);
        if (b < l || r < a) return IDENTITY;
        if (a <= l && r <= b) return seg[no];
        int m = (l + r) / 2, e = no * 2, d = e + 1;

        return join(query(e, l, m, a, b), query(d, m + 1, r, a, b));
    }

    void update(int no, int l, int r, int a, int b, T v) {
        unlazy(no, l, r);
        if (b < l || r < a) return;
        if (a <= l && r <= b) {
            lazy[no] += v;
            return unlazy(no, l, r);
        }
        int m = (l + r) / 2, e = no * 2, d = e + 1;

        update(e, l, m, a, b, v);
        update(d, m + 1, r, a, b, v);

        seg[no] = join(seg[e], seg[d]);
    }

    void build(int no, int l, int r, vector<int>& arr) {
        if (l == r) {
            seg[no] = arr[l];
            return;
        }
        int m = (l + r) / 2, e = no * 2, d = e + 1;

        build(e, l, m, arr);
        build(d, m + 1, r, arr);

        seg[no] = join(seg[e], seg[d]);
    }

    T query(int ls, int rs) { return query(1, 0, N - 1, ls, rs); }
    void update(int ls, int rs, T v) { update(1, 0, N - 1, ls, rs, v); }
};

int solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int q;
    cin >> q;

    vector<int> arr(n);
    arr[0] = (s[0] == ')' ? -1 : +1);
    for (int i = 1; i < n; i++) arr[i] = arr[i - 1] + (s[i] == ')' ? -1 : +1);

    SegTree<int> seg(arr);

    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        if (x == 0)
            cout << (seg.query(0, n - 1) >= 0 && seg.query(n - 1, n - 1) == 0 ? "YES" : "NO") << '\n';
        else {
            x--;

            if (s[x] == '(') {
                s[x] = ')';
                seg.update(x, n - 1, -2);
            } else {
                s[x] = '(';
                seg.update(x, n - 1, +2);
            }
        }
    }

    return 0;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c = 1;
    int tc = 10;
    while (tc--) {
        cout << "Test " << c++ << ":" << '\n';
        solve();
    }

    return 0;
}