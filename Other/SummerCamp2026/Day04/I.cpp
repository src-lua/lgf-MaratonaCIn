/**
 * Author:      Lua
 * Problem:     I
 * Link:        https://vjudge.net/contest/783478#problem/I
 * Status:      AC
 * Created:     29-01-2026 11:21:13
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll,ll>;


using T = int;

struct PT {
    T x, y;
    PT(T _x = 0, T _y = 0) : x(_x), y(_y){}
    PT operator -(const PT &p) const { return PT(x-p.x,y-p.y); }
    T operator *(const PT &p)  const { return x*p.x+y*p.y;     }
    T operator %(const PT &p)  const { return x*p.y-y*p.x;     }

    bool operator < (const PT &p) const { return x != p.x ? x < p.x : y < p.y; }
    bool operator == (const PT &p)const { return x == p.x && y == p.y; }
};

std::vector<PT> ConvexHull (std::vector<PT> pts, bool needs = true) {
    if(needs) {
        std::sort(pts.begin(), pts.end());
    }
    pts.resize(std::unique(pts.begin(), pts.end()) - pts.begin());
    if(pts.size() <= 1) return pts;
    std::vector<PT> ans(pts.size() * 2 + 1);
    int s = 0;
    for(int i = 0; i < (int) pts.size(); i++) {
        while(s > 1 && (pts[i] - ans[s - 2]) % (ans[s - 1] - ans[s - 2]) >= 0) {
            s--;
        }
        ans[s++] = pts[i];
    }
    for(int i = (int) pts.size() - 2, t = s + 1; i >= 0; i--) {
        while(s >= t && (pts[i] - ans[s - 2]) % (ans[s - 1] - ans[s - 2]) >= 0) {
            s--;
        }
        ans[s++] = pts[i];
    }
    ans.resize(s-1);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n; cin >> n;
    while (n != 0) {
        vector<PT> arr(n);
        for (auto &[x, y] : arr) cin >> x >> y;

        auto h = ConvexHull(arr);
        cout << h.size() << '\n';
        for (auto [x, y] : h) cout << x << ' ' << y << '\n';

        cin >> n;
    }

    return 0;
}