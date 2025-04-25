#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve(int r, int g, int idx) {
    if (r == 0 || g == 0) return 1;
    if (idx == 1) {
        if (r > 0 && g > 0) return 2;
        else return 1;
    }

    int answ = 0;
    if (r >= idx) answ += solve(r-idx, g, idx-1);
    if (g >= idx) answ += solve(r, g-idx, idx-1);

    return answ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int r, g; cin >> r >> g;
    int n = ((1 + sqrt(1+8*(r+g))) / 2) - 1;

    cout << solve(r,g,n);

    return 0;
}