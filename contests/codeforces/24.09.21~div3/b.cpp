#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int n, k; cin >> n >> k; 

    //multiplos de 4 - 1 ou - 0 são pares , multiplos de 4 - 3 ou -2 são impares

    if (n % 4 == 0 || n % 4 == 3) {
        if (n-k > 0) {
            if ((n-k) % 4 == 0 || (n-k) % 4 == 3) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
        else {
            cout << "YES" << endl;
        }
    }

    else {
        if (n-k > 0) {
            if ((n-k) % 4 == 0 || (n-k) % 4 == 3) {
                cout << "NO" << endl;
            }
            else {
                cout << "YES" << endl;
            }
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}