#include <bits/stdc++.h>

#define endl '\n
#define int long long

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    int x;

    int l = -1;
    int answ = 1;

    bool hasansw = false;

    for (int i = 0; i < n; i++) {
        cin >> x;

        if (x == 0 && l != -1) {
            l++;
        } else if (x == 1) {
            hasansw = true;
            answ *= l;
            l = 1;
        }
    }
    
    if (hasansw) cout << abs(answ) << '\n';
    else cout << 0 << '\n';
    
    return 0;
}