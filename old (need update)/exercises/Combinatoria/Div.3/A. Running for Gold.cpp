#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
const int INF = INT_MAX;

bool check(vector<int>& checker, vector<int>& winner) {
    int c = 0;
    for (size_t i = 0; i < 5; i++) {
        if (checker[i] <= winner[i]) c++;
    }

    return c >= 3;
}

int solve() {

    int n; cin >> n;

    vector<vector<int>> v(n, vector<int>(5));

    vector<int> winner(5,INF);
    int winner_index = -1;

    for (size_t i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2] >> v[i][3] >> v[i][4];
    }

    for (int i = 0; i < n; i++) {
        if (check(v[i], winner)) {
            winner = v[i];
            winner_index = i;
        }
    }

    bool answ = true;

    for (int i = 0; i < winner_index; i++) {
        if (check(v[i], winner)) {
            if (!(check(winner, v[i]))){
                answ = false;
                break;
            }
        }
    }
    
    if (answ) {
        cout << winner_index + 1 << '\n';
    } else {
        cout << -1 << '\n';
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