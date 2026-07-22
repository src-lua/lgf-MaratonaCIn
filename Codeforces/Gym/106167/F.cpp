/**
 * Author:      Lua
 * Problem:     F
 * Link:        https://codeforces.com/gym/106167/problem/F
 * Status:      ~
 * Tags:        
 * Created:     22-07-2026 08:28:05
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Point {
    ll x, y;

    bool operator!=(const Point& o) const { return tie(x,y) != tie(o.x, o.y); }
};

struct fract {
    ll num, dem;

    fract(ll num = 0, ll dem = 1) : num(num), dem(dem) {};

    bool operator< (const fract& o) const { return num * o.dem < o.num * dem; }
    bool operator> (const fract& o) const { return o < *this; }
    bool operator<=(const fract& o) const { return !(o < *this); }
    bool operator>=(const fract& o) const { return !(*this < o); }
    bool operator==(const fract& o) const { return num * o.dem == o.num * dem; }
};

ll ccw(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Point s, e;
    cin >> s.x >> s.y;
    cin >> e.x >> e.y;

    int n; cin >> n;
    vector<pair<Point, Point>> intervals(n+1);
    for (int i = 0; i < n; i++) {
        auto &[first, secnd] = intervals[i];
        int x, y_1, y_2; cin >> x >> y_1 >> y_2;
        if (y_1 > y_2) swap(y_1, y_2);
        first = {x, y_1}, secnd = {x, y_2};
    } intervals[n] = {e, e};

    vector<Point> path; path.push_back(s);
    
    deque<Point> U, L;
    U.push_back(s);
    L.push_back(s);

    int i = 0;
    while (i <= n) {
        Point p_bot = intervals[i].first;
        Point p_top = intervals[i].second;

        if (U.size() > 1 && ccw(U[0], U[1], p_bot) > 0) {
            Point new_pivot = U[1];
            path.push_back(new_pivot);
            U.pop_front();
            
            L.clear(); 
            L.push_back(new_pivot);
            
            continue; 
        }

        if (L.size() > 1 && ccw(L[0], L[1], p_top) < 0) {
            Point new_pivot = L[1];
            path.push_back(new_pivot);
            L.pop_front();
            
            U.clear(); 
            U.push_back(new_pivot);
            
            continue;
        }

        while (U.size() > 1 && ccw(U[U.size() - 2], U.back(), p_top) <= 0)
            U.pop_back();
        U.push_back(p_top);

        while (L.size() > 1 && ccw(L[L.size() - 2], L.back(), p_bot) >= 0)
            L.pop_back();
        L.push_back(p_bot);

        i++;
    } if (path.back() != e) path.push_back(e);

    for (auto [x, y] : path) cout << x << ' ' << y << '\n';

    return 0;
}
