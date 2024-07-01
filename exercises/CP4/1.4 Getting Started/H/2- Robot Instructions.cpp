#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {
    int n;
    cin >> n;
    vector<string> v(n);
    string s;

    int x;
    int answ = 0;

    for (int i = 0; i < n; i++) {
        cin >> v[i];

        if (v[i] == "SAME") {
            cin >> v[i] >> x;
            v[i] = v[x - 1];
        }

        if (v[i] == "LEFT") {
            answ--;
        } else {
            answ++;
        }
    }

    cout << answ << endl;

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}