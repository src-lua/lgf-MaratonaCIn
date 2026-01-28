#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c, d;
    int score1, score2;

    while (1) {
        cin >> a >> b >> c >> d;

        if (a == 0 && b == 0 && c == 0 && d == 0) return 0;

        if (max(a, b) == 2 && min(a, b) == 1) {
            score1 = 1000;
        } else if (a == b) {
            score1 = 100 * a;
        } else {
            score1 = max(a, b) * 10 + min(a, b);
        }

        if (max(c, d) == 2 && min(c, d) == 1) {
            score2 = 1000;
        } else if (c == d) {
            score2 = 100 * c;
        } else {
            score2 = max(c, d) * 10 + min(c, d);
        }

        if (score1 > score2)
            cout << "Player 1 wins." << endl;
        else if (score1 < score2)
            cout << "Player 2 wins." << endl;
        else
            cout << "Tie." << endl;
    }

    return 0;
}