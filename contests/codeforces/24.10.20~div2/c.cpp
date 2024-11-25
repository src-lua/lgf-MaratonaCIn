#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using pii = pair<int,int>;
using iii = tuple<int,int,int>;

int solve() {

    int n; cin >> n;

    map<int, vector<iii>> m;
    vector<pii> arr(n);

    int a, b;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;

        m[a+b].push_back({min(a,b),max(a,b), i});
        arr[i] = {a,b};
    }

    for (auto [_, v] : m) {
        sort(v.begin(), v.end());
        for (auto [__, ___, idx] : v) {
            cout << arr[idx].first << ' ' << arr[idx].second << ' ';
        }
    }

    cout << '\n';

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