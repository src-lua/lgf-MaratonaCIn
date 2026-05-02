/**
 * Author:      Lua
 * Problem:     D
 * Link:        https://codeforces.com/gym/101492/problem/D
 * Status:      ~
 * Created:     01-05-2026 09:34:33
 **/

#include <bits/stdc++.h>

using namespace std;
using ld = long double;
using pii = pair<ld,ld>;

struct point {
    ld x, y;

    bool operator<(point o) { return (x == o.x ? y >= o.y : x < o.x); }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cout << setprecision(10) << fixed;

    int n; cin >> n;
    vector<point> arr(n);

    for (auto &[x, y] : arr) cin >> x >> y;
    sort(arr.begin(), arr.end());
    arr.push_back(arr[0]);
    
    double min_x = INFINITY, max_x = -INFINITY;

    for (int i = 0; i < n; i++) {
        if (arr[i+1].x == arr[i].x) continue;
        double slope = (arr[i+1].y-arr[i].y)/(arr[i+1].x-arr[i].x);
        min_x = min(min_x, slope), max_x = max(max_x, slope);
    }

    vector<point> arr2(n);
    for (int i = 0; i < n; i++) arr2[i] = {1/arr[i].x, arr[i].y/arr[i].x};
    sort(arr2.begin(), arr2.end());
    arr2.push_back(arr2[0]);

    double min_y = INFINITY, max_y = -INFINITY;

    for (int i = 0; i < n; i++) {
        if (arr2[i+1].x == arr2[i].x) continue;
        double slope = (arr2[i+1].y-arr2[i].y)/(arr2[i+1].x-arr2[i].x);
        min_y = min(min_y, -slope), max_y = max(max_y, -slope);
    }

    cout << min_x << ' ' << min_y << ' ' << max_x << ' ' << max_y << endl;

    return 0;
}
