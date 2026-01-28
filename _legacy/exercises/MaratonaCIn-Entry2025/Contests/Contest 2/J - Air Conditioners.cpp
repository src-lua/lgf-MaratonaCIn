#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

// Time Complexity: O(V + E)
void bfs(int n, vector<ll>& temperature, vector<int>& start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> operation_order;

    for(auto e : start) {
        operation_order.push({temperature[e], e});
    }

    while (!operation_order.empty()) {
        auto [_, top] = operation_order.top();
        operation_order.pop();

        for (auto d : {1, -1}) {
            int x = top+d;
            if (x < 0 || x >= n) continue;
            if (temperature[x] > temperature[top] + 1) {
                temperature[x] = temperature[top] + 1;
                operation_order.push({temperature[x], x});
            }
        }
    }
}

int solve() {

    int n, k; cin >> n >> k;

    vector<ll> temperature(n, LLONG_MAX);

    vector<int> pos(k);
    
    for (int i = 0; i < k; i++) {
        cin >> pos[i];
        pos[i]--;
    }
    
    for (int i = 0; i < k; i++) {
        cin >> temperature[pos[i]];
    }

    bfs(n, temperature, pos);

    for (auto e : temperature) cout << e << ' ';
    cout << endl;

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}