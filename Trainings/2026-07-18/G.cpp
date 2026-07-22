/**
 * Author:      Lua
 * Problem:     G
 * Link:        https://codeforces.com/group/btcK4I5D5f/contest/701070/problem/G
 * Status:      ~
 * Tags:        
 * Created:     18-07-2026 08:31:07
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int f[11];

void build(int n) {
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] * i;
    }
}

inline int encode(const string& p) {
    int n = p.size();
    int res = 0;
    for (int i = 0; i < n; i++) {
        int inv = 0;
        for (int j = i + 1; j < n; j++) {
            if (p[j] < p[i]) inv++;
        }
        res += inv * f[n - 1 - i];
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n; build(n);
    string arr; arr.reserve(n); for (int i = 0; i < n; i++) {
        int x; cin >> x; x--;
        arr.push_back(x);
    }

    string ref; ref.reserve(n); for (int i = 0; i < n; i++) {
        ref.push_back(i);
    }

    vector<int> dist1(f[n]+1, -1), dist2(f[n]+1, -1);
    queue<string> q1, q2;

    q1.push(arr); dist1[encode(arr)] = 0;
    q2.push(ref); dist2[encode(ref)] = 0;

    if (encode(arr) == encode(ref)) {
        cout << 0 << '\n';
        return 0;
    }

    int ans = 0;

    while(!q1.empty() && !q2.empty()) {
    {
        auto u = q1.front(); q1.pop();
        int u_id = encode(u);

        for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
            reverse(u.begin()+i, u.begin()+j+1);
            int v_id = encode(u);
            if (dist1[v_id] == -1) dist1[v_id] = dist1[u_id]+1, q1.push(u);
            reverse(u.begin()+i, u.begin()+j+1);

            if(dist2[v_id] != -1) {
                ans = dist1[v_id] + dist2[v_id];
                goto hasans;
            }
        }
    }
    {
        auto u = q2.front(); q2.pop();
        int u_id = encode(u);

        for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
            reverse(u.begin()+i, u.begin()+j+1);
            int v_id = encode(u);
            if (dist2[v_id] == -1) dist2[v_id] = dist2[u_id]+1, q2.push(u);
            reverse(u.begin()+i, u.begin()+j+1);

            if(dist1[   v_id] != -1) {
                ans = dist1[v_id] + dist2[v_id];
                goto hasans;
            }
        }
    }
    }

    hasans:
    cout << ans << '\n';

    return 0;
}
