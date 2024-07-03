#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int n; cin >> n;

    vector<pair<int, int>> v(n);

    int sum = 0;

    for (int i = 0; i < n; i++) {
        v[i].second = i+1;
        cin >> v[i].first;
        sum += v[i].first;
    }

    sort(v.rbegin(), v.rend());

    if (v.size() > 1 && v[0].first == v[1].first) {
        cout << "no winner" << endl;
    }
    else if (v[0].first > sum/2) {
        cout << "majority winner " << v[0].second << endl;
    } else {
        cout << "minority winner " << v[0].second << endl;
    }

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