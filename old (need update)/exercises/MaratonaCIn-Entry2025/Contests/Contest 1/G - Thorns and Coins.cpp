#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int n; cin >> n;
    string s; cin >> s;

    int answ = 0;

    bool flag = false;

    for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
            if (flag) break;
            flag = true;
        }
        else {
            flag = false;
            if (s[i] == '@') answ++;
        }
    }

    cout << answ << endl;
    
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