/**
 * Author:      Lua
 * Problem:     G
 * Link:        https://vjudge.net/contest/783195#problem/G
 * Status:      AC
 * Created:     30-01-2026 20:41:29
 **/

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

    aabb box() {
        return {
            {c.x-r, c.y-r},
            {c.x+r, c.y+r}
        };
    }

    bool collide(circle& o) {
        return dist2(c, o.c) <= (r + o.r)*(r + o.r);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll m, n, k; cin >> m >> n >> k;

    vector<circle> arr(k);
    for (auto &[c, r] : arr) cin >> c.x >> c.y >> r;

    vector<aabb> boxes;

    vector<int> group(k, -1); // dsu inplace

    for (int i = 0; i < k; i++) {
        if (group[i] == -1) {
            group[i] = boxes.size();
            boxes.push_back(arr[i].box());
        }

        for (int j = i; j < k; j++) {
            if (arr[i].collide(arr[j])) {
                if (group[j] != -1) 
                    boxes[group[j] = group[i]].join(boxes[group[j]]);
                else
                    boxes[group[j] = group[i]].join(arr[j].box());
            }
        }
    }

    bool ans = true;

    for (auto box : boxes) {
        bool u = box.a.y <= 0, d = box.b.y >= n;
        bool l = box.a.x <= 0, r = box.b.x >= m;

        if ((u && l) || (u && d) || (l && r) || (r && d)) {
            ans = false; break;
        }
    }

    cout << (ans ? "S\n" : "N\n");

    return 0;
}