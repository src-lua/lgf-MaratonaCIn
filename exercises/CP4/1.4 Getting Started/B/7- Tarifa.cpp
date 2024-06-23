#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k, n;
    cin >> k >> n;

    k *= n + 1;

    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        k -= a;
    }

    cout << k;

    return 0;
}