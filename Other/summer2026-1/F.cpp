/**
 * Author:      Lua
 * Problem:     F
 * Link:        https://vjudge.net/contest/781528#problem/F
 * Status:      AC
 * Created:     28-01-2026 16:15:44
 **/

#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;

inline int sum(int a, int b) { return a + b; }

const int inf = 1e9;
struct Node {
    Node *l = 0, *r = 0;
    int lo, hi, mset = inf, madd = 0, val = 0;
    Node(int lo, int hi) : lo(lo), hi(hi) {}
    Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo) / 2;
            l = new Node(v, lo, mid);
            r = new Node(v, mid, hi);
            val = sum(l->val, r->val);
        } else
            val = v[lo];
    }
    int query(int L, int R) {
        if (R <= lo || hi <= L) return 0;
        if (L <= lo && hi <= R) return val;
        push();
        return sum(l->query(L, R), r->query(L, R));
    }
    void set(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R)
            mset = x, madd = 0, val = (hi - lo) * x;
        else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = sum(l->val, r->val);
        }
    }
    void add(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            if (mset != inf)
                mset += x;
            else
                madd += x;
            val += x;
        } else {
            push(), l->add(L, R, x), r->add(L, R, x);
            val = sum(l->val, r->val);
        }
    }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo) / 2;
            l = new Node(lo, mid);
            r = new Node(mid, hi);
        }
        if (mset != inf)
            l->set(lo, hi, mset), r->set(lo, hi, mset), mset = inf;
        else if (madd)
            l->add(lo, hi, madd), r->add(lo, hi, madd), madd = 0;
    }
};

int solve() {
    int n;
    cin >> n;
    vector<pii> arr(n);
    for (auto& [l, r] : arr) cin >> l >> r;
    reverse(arr.begin(), arr.end());

    set<int> cords;
    for (auto const& [l, r] : arr) {
        cords.insert(l), cords.insert(r);
        cords.insert(r + 1);
    }
    map<int, int> compress;
    int c = 0;
    for (auto const& e : cords) compress[e] = c++;

    vector<int> init_seg(c, 0);
    Node* seg = new Node(init_seg, 0, c);

    int ans = 0;
    for (auto const& [l, r] : arr) {
        int L = compress[l], R = compress[r];
        if (seg->query(L, R + 1) != R + 1 - L) {
            seg->set(L, R + 1, 1);
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}