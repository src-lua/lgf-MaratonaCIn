/**
 * Author:      Lua
 * Problem:     B
 * Link:        https://codeforces.com/group/btcK4I5D5f/contest/689113/problem/B
 * Status:      AC
 * Created:     02-05-2026 08:53:00
 **/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;

    cout << (n == 45 ? "Ambos\n" : (n < 45 ? "Costa\n" : "Saad\n") );

    return 0;
}
