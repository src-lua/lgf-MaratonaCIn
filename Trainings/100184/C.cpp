/**
 * Author:      Lua
 * Problem:     C
 * Link:        https://codeforces.com/gym/100184/problem/C
 * Status:      ~
 * Created:     16-05-2026 08:41:06
 **/

#include <bits/stdc++.h>

using namespace std;
using iii = tuple<int,int,int>;

struct Hole {
    int min_dist, count, m, l, r;

    bool operator<(const Hole& o) const {
        return tie(min_dist, count, m) < tie(o.min_dist, o.count, o.m);
    }
};

Hole get_hole(int l, int r, int n) {
    int best_dist = -1, best_cnt = -3, best_m = -1;
    
    vector<int> candidates = {l, r, l + (r - l) / 2, l + (r - l + 1) / 2};

    for (int m : candidates) {
        if (m < l || m > r) continue;

        int dist_l = (l > 1) ? (m - (l - 1)) : 2e9;
        int dist_r = (r < n) ? ((r + 1) - m) : 2e9;

        int min_dist = min(dist_l, dist_r);
        
        int count = 0;
        if (l > 1 && dist_l == min_dist) count--;
        if (r < n && dist_r == min_dist) count--;

        if (tie(min_dist, count, m) > tie(best_dist, best_cnt, best_m)) {
            best_dist = min_dist;
            best_cnt = count;
            best_m = m;
        }
    }

    return {best_dist, best_cnt, best_m, l, r};
}

int put(priority_queue<Hole>& pq, set<int>& s, int n) {
    while(!pq.empty()) {
        Hole h = pq.top(); pq.pop();
        
        auto it = s.lower_bound(h.l);
        if (it != s.end() && *it <= h.r) continue;

        s.insert(h.m);

        int new_r = h.m - 1, new_l = h.m + 1;
        if (h.l <= new_r) pq.push(get_hole(h.l, new_r, n));
        if (new_l <= h.r) pq.push(get_hole(new_l, h.r, n));

        return h.m;
    }

    return -1;
}

void rmv(int x, priority_queue<Hole>& pq, set<int>& s, int n) {
    auto it = s.find(x);
    
    int l = 1;
    if (it != s.begin()) {
        l = *prev(it) + 1;
    }

    int r = n;
    auto prox = next(it);
    if (prox != s.end()) {
        r = *prox - 1;
    }

    s.erase(it);
    pq.push(get_hole(l, r, n));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q; cin >> n >> q;
    set<int> s;
    priority_queue<Hole> pq;
    pq.push(get_hole(1, n, n));

    vector<int> putted;

    for (int i = 0; i < q; i++) {
        int c; cin >> c;
        if (c == 0) {
            c = put(pq, s, n);
            cout << c << '\n';
        }
        else {
            int pos; cin >> pos; pos--;
            rmv(putted[pos], pq, s, n);
        }
        putted.push_back(c);
    }

    return 0;
}
