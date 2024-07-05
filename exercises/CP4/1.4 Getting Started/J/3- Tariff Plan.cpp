#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int n; cin >> n;

    int score1 = 0;
    int score2 = 0;

    int x;

    for (int i = 0; i < n; i++) {
        cin >> x;

        score1 += ((x/30) + 1) * 10;
        score2 += ((x/60) + 1) * 15;
    }

    if (score1 < score2) {
        cout << "Mile " << score1 << endl;
    }
    else if (score1 > score2) {
        cout << "Juice " << score2 << endl;
    }
    else { // (score1 == score2)
        cout << "Mile Juice " << score1 << endl; 
    }
    

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c = 0;
    int tc; cin >> tc; while (tc--) {
        cout << "Case " << ++c << ": ";
        solve();
    }

    return 0;
}