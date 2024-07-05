#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int n, m; cin >> n >> m;

    vector<vector<int>> prizes(n);
    vector<int> values(n);

    int k;

    for (int i = 0; i < n; i++) {
        cin >> k;
        prizes[i] = vector<int>(k);
        for (int j = 0; j < k; j++) {
            cin >> prizes[i][j];
        }
        cin >> values[i];
    }

    vector<int> stickers(m);

    for (int i = 0; i < m; i++) {
        cin >> stickers[i];
    }

    int answ = 0;

    for (int i = 0; i < n; i++) {
        int minStickers = INT_MAX;
        for (size_t j = 0; j < prizes[i].size(); j++) {
            minStickers = min(minStickers, stickers[prizes[i][j]-1]);
        }
        answ += minStickers * values[i];
    }

    cout << answ << endl;

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