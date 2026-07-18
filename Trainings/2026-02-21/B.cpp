/**
 * Author:      Lua
 * Problem:     B - Ali and Wi-Fi
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/101915/problem/B
 * Status:      ~
 * Created:     21-02-2026 08:03:55
 **/

#include <bits/stdc++.h>
using ll = long long int;
using ld = double;

using namespace std;

const ld eps = 1e-6;
const ld dx[9] = {1.0, sqrt(2)/2, 0.0, -sqrt(2)/2, -1.0, -sqrt(2)/2, 0.0, sqrt(2)/2, 0};
const ld dy[9] = {0.0, sqrt(2)/2, 1.0, sqrt(2)/2, 0.0, -sqrt(2)/2, -1.0, -sqrt(2)/2, 0};

struct point {
    ld x, y;
};

ld dist2(point& a, point& b) {
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

ld dist(point&a, point&b) {
    return sqrt(dist2(a, b));
}

struct circle {
    point c;
    ld r;

    bool collide(circle& o) {
        return dist2(c, o.c) <= (r + o.r)*(r + o.r);
    }

    vector<point> intersect(circle& o) {
        vector<point> ans;
        ld d = dist(c, o.c);
        
        if (d > r + o.r || d < abs(r - o.r) || d < eps) return ans;

        ld a = (r * r - o.r * o.r + d * d) / (2.0 * d);
        ld h = sqrt(max(0.0, r * r - a * a));

        point p3 = {c.x + a * (o.c.x - c.x) / d, c.y + a * (o.c.y - c.y) / d};

        ans.push_back({
            p3.x + h * (o.c.y - c.y) / d,
            p3.y - h * (o.c.x - c.x) / d
        });


        if (h > eps) {
            ans.push_back({
                p3.x - h * (o.c.y - c.y) / d,
                p3.y + h * (o.c.x - c.x) / d
            });
        }
        
        return ans;
    }
};

void solve() {
    int n, m; cin >> n >> m;

    vector<circle> arr(n);
    vector<int> speed(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].c.x >> arr[i].c.y >> arr[i].r >> speed[i];
    }
    
    vector<point> interest;

    for (int i = 0; i < n; i++) {
        interest.push_back(arr[i].c);
        for (int j = i + 1; j < n; j++) {
            if (arr[i].collide(arr[j])) {
                vector<point> pts = arr[i].intersect(arr[j]);
                interest.insert(interest.end(), pts.begin(), pts.end());
            }
        }
    }

    int ans = 0;
    vector<int> candidates;
    candidates.reserve(n);

    for (auto p : interest) {
        for (int d = 0; d < 9; d++) {
            point P = {p.x + dx[d]*1e-5, p.y + dy[d]*1e-5};

            candidates.clear();
            for (int i = 0; i < n; i++) {
                if (dist2(arr[i].c, P) - (arr[i].r * arr[i].r) <= eps)
                    candidates.push_back(speed[i]);
            }

            int curr = 0;
            sort(candidates.rbegin(), candidates.rend());
            for (int i = 0; i < min(m, (int)candidates.size()); i++)
                curr += candidates[i];
            ans = max(ans, curr);
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tc; cin >> tc; while(tc--) solve();

    return 0;
}
