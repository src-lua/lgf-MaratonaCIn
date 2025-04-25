#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int x;
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> x;
        while (x%2 == 0) x/=2;
        while (x%3 == 0) x/=3;
        s.insert(x);
    }
    if (s.size() == 1) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}