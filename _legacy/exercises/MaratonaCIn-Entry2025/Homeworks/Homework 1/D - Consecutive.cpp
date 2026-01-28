#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;

    string s;
    cin >> s;

    vector<int> prefix(n+1);
    prefix[0] = 0;

    int x;
    for (int i = 1; i <= n; i++) {
        if (s[i] == s[i-1]) x = 1;
        else x = 0;

        prefix[i] = prefix[i-1] + x;
    }

    int l, r;
    for (int i = 0; i < q; i++) {
        cin >> l >> r;

        cout << prefix[r-1] - prefix[l-1] << '\n';
    }

    return 0;
}