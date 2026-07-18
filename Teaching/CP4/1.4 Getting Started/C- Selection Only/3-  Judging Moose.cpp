#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int l, r;
    cin >> l >> r;

    if (l == 0 && r == 0) {
        cout << "Not a moose" << '\n';
    }
    else if (l == r) {
        cout << "Even " << l + r << '\n';
    } else {
        cout << "Odd " << max(l, r) * 2 << '\n';
    }

    return 0;
}