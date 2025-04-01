#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int x;
    vector<pair<int, int>> v;

    v.push_back({0, 1});

    for (int i = 2; i <= n; i++) {
        cin >> x;

        v.push_back({x, i});
    }

    sort(v.begin(), v.end());

    for (auto e : v) {
        cout << e.second << ' ';
    } cout << endl;

    return 0;
}