#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    map<int,int> m;

    int x;
    for (int i = 0; i < k; i++) {
        cin >> x;
        m[x]++;
    }

    set<int> s;

    for (auto [k, v] : m) {
        if (v >= n) s.insert(k);
    }

    cout << s.size() << endl;
    for (auto e : s) cout << e << ' ';
    cout << endl;

    return 0;
}