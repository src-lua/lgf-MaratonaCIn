/**
 * Author:      Lua
 * Problem:     B - Button Bashing
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/101512/problem/B
 * Status:      AC
 * Created:     21-03-2026 09:04:56
 **/

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, t; cin >> n >> t;

    vector<int> arr(n); for (auto &x : arr) cin >> x;
    vector<int> dist(3601, INT_MAX); dist[0] = 0;
    vector<bool> visited(3601, false);
    queue<int> q; q.push(0);

    while(!q.empty()) {
        int i = q.front(); q.pop(); 
        if (visited[i]) continue; 
        visited[i] = true;
        for (int j = 0; j < n; j++) {
            int x = clamp(i + arr[j], 0, 3600);
            if (visited[x]) continue;
            dist[x] = min(dist[x], dist[i] + 1);
            q.push(x);
        }
    }

    for (int i = t; i <= 3600; i++) {
        if (dist[i] != INT_MAX) {
            return cout << dist[i] << ' ' << i-t << '\n', void();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tc; cin >> tc; while(tc--) solve();

    return 0;
}
