#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int n; cin >> n;


    vector<vector<string>> people(3, vector<string>(n));
    map<string, int> m;

    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < n; i++) {
            cin >> people[j][i];
            m[people[j][i]]++;
        }
    }


    for (int i = 0; i < 3; i++) {
        long long int answ = 0;
        for (auto e : people[i]) {
            if (m[e] == 1) answ += 3;
            if (m[e] == 2) answ += 1;
        }
        cout << answ << ' ';
    } cout << '\n';

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