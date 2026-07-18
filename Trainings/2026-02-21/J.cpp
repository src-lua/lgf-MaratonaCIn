/**
 * Author:      Lua
 * Problem:     J - The Volcano Eruption
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/101915/problem/J
 * Status:      AC
 * Created:     21-02-2026 08:03:55
 **/

#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

struct point {
    ll x, y;
};

ll dist2 (point& a, point& b) {
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

struct aabb {
    point a, b;

    void join(const aabb& o) {
        a.x = min(a.x, o.a.x), a.y = min(a.y, o.a.y);
        b.x = max(b.x, o.b.x), b.y = max(b.y, o.b.y);
    }
};

struct circle {
    point c;
    ll r;

    aabb box() const {
        return {
            {c.x-r, c.y-r},
            {c.x+r, c.y+r}
        };
    }

    bool collide(circle& o) {
        return dist2(c, o.c) <= (r + o.r)*(r + o.r);
    }
};

struct DSU {
    vector<int> parent;
    vector<aabb> boxes;

    DSU(int n, const vector<circle>& arr) {
        parent.resize(n);
        boxes.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            boxes[i] = arr[i].box();
        }
    }

    int find(int i) {
        return (parent[i] == i ? i : find(parent[i]));
    }

    void join(int i, int j) {
        i = find(i), j = find(j);
        if (i == j) return;

        parent[j] = i;
        boxes[i].join(boxes[j]);
    }
};

void solve() {
    ll m, n, k; cin >> k >> m >> n;

    vector<circle> arr(k);
    for (auto &[c, r] : arr) cin >> c.x >> c.y >> r;

    DSU dsu(k, arr);

    for (int i = 0; i < k; i++)
        for (int j = i + 1; j < k; j++)
            if (arr[i].collide(arr[j]))
                dsu.join(i, j); 

    int ans = 0;

    for (int i = 0; i < k; i++) {
        if (dsu.parent[i] != i) continue; 
        auto box = dsu.boxes[i];
        bool l = box.a.x <= 0;
        bool r = box.b.x >= m;
        
        if (l && r) ans++;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tc; cin >> tc; while(tc--) solve();

    return 0;
}