/**
 * Author:      Lua
 * Problem:     A
 * Link:        https://codeforces.com/group/btcK4I5D5f/contest/689113/problem/A
 * Status:      AC
 * Created:     02-05-2026 08:53:00
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Tag {
    ll x;
    Tag(ll x = 0) : x(x) {}

    void compose(const Tag& t) {
        x += t.x;
    }
    void apply(ll& val) { val += x; }
};

template<typename T, typename TAG>
struct DualSegTree {
    int N;
    vector<TAG> lazy;
    vector<T> leaves;

    DualSegTree(int n) : N(n), lazy(4 * n), leaves(n) {}
    DualSegTree(const vector<T>& v) : N(v.size()), lazy(4 * v.size()), leaves(v) {}

    void push(int no, int l, int r) {
        int e = no << 1;
        int d = e | 1;
        lazy[e].compose(lazy[no]);
        lazy[d].compose(lazy[no]);
        lazy[no] = TAG();
    }

    void update(int no, int l, int r, int a, int b, const TAG& v) {
        if (b < l || r < a) return;
        if (a <= l && r <= b) {
            lazy[no].compose(v);
            return;
        }
        push(no, l, r);
        int m = (l + r) >> 1;
        update(no << 1, l, m, a, b, v);
        update((no << 1) | 1, m+1, r, a, b, v);
    }

    T get(int no, int l, int r, int idx) {
        if (l == r) {
            T res = leaves[idx];
            lazy[no].apply(res);
            return res;
        }
        push(no, l, r);
        int m = (l + r) >> 1;
        if (idx <= m) return get(no << 1, l, m, idx);
        else return get((no << 1) | 1, m + 1, r, idx);
    }

    void update(int l, int r, const TAG& t) { update(1, 0, N-1, l, r, t); }
    T get(int idx) { return get(1, 0, N-1, idx); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k; cin >> n >> k;
    vector<ll> arr(n);
    for (auto &x : arr) cin >> x;
    DualSegTree<ll, Tag> seg(arr);

    vector<pair<int, ll>> updates;

    for (int i = 0; i < k; i++) {
        int idx, val; cin >> idx >> val; idx--;
        updates.emplace_back(idx, val);
    }

    sort(updates.begin(), updates.end());
    
    int curr = 1;
    int j = 0;
    for (int i = 1; i < n; i++) {
        while(j < updates.size() && updates[j].first <= i) {
            auto [idx, val] = updates[j];
            seg.update(0, idx, {val});
            j++;
        }

        cout << curr << '\n';
        seg.get(i) < seg.get(i-1) ? curr++ : curr = 1;
    }

    return 0;
}
