#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c, n;
    cin >> a >> b >> c >> n;

    if (a > 0 && b > 0 && c > 0 && a + b + c >= n && n >= 3) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}