#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int m;
    cin >> m;

    vector<int> u(m + 1);

    for (int i = 1; i <= m; i++) {
        cin >> u[i];
    }

    int k;
    int x;

    vector<int> costs;

    for (int i = 0; i < n; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> x;
            costs.push_back(v[i] + u[x]);
        }
    }

    sort(costs.begin(), costs.end());

    int money;
    cin >> money;

    cout << max(money / costs[0] - 1, 0) << endl;

    return 0;
}