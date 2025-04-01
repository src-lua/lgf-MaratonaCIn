#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    string s; cin >> s;
    int current = 0;
    int sum = 0;

    for (auto e : s) {
        if (e == 'O') {
            sum += ++current;
        } else {
            current = 0;
        }
    }

    cout << sum << endl;

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