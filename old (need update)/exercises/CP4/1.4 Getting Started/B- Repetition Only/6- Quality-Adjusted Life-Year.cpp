#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    double a, b;
    double answ;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;

        answ += a * b;
    }

    cout << answ;

    return 0;
}