#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int n; int k; cin >> n >> k;

    if (k == 1) {
        cout << n << '\n';
        return 0;
    }

    int c = 0;

    for (int i = 1; i*i <= k && i < min(n, k); i++) {
        if ((k-1) % i == 0) {
            c++;
            if ((k-1)/i != i && (k-1)/i <= min(n, k)) {
                c++;
            }
        }
    }

    cout << c << '\n';
    
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}