#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;
    long long sum = 0;

    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        sum += x;
    }

    if (sum + ((n-1) * 10) > k) cout << "-1\n";
    else cout << (k - (sum + ((n-1) * 10)))/5 + (n-1)*2;

    return 0;
}