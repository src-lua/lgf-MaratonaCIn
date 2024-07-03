#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int r, c;

    int x, prev;

    while (1) {
        cin >> r;

        if (!r) return 0;

        cin >> c;

        cin >> prev;

        int answ = 0;

        for (int i = 1; i < c; i++) {
            cin >> x;

            answ += max(0, x - prev);

            prev = x;
        }
        answ += max(0, r - prev);

        cout << answ << '\n';
    }
}