#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using pii = pair<int,int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x1, y1, x2, y2;

    map<pii, vector<pii>> m;

    for (int i = 0; i < 4; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        if (!(x1 == x2 ^ y1 == y2)) {
            cout << "NO\n";
            return 0;
        }
        m[{x1,y1}].push_back({x2,y2});
        m[{x2,y2}].push_back({x1,y1});
    }
    
    if (m.size() != 4) {
        cout << "NO\n";
        return 0;
    }

    for (auto [k, v] : m) {
        if (v.size() != 2 || (v[0].first == v[1].first || v[0].second == v[1].second)) {
            cout << "NO\n";
            return 0;
        }
    }
    
    cout << "YES\n";

    return 0;
}