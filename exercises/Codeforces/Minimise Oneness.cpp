/*                                          
  Lucas Guimarães Fernandes </lgf_cin>
  MaratonaCIn @ CIn - UFPE

  [Minimise Oneness](codeforces.com/contest/2030/problem/B)
  Status: Accepted
*/

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int n; cin >> n;
    cout << 1;
    for (int i = 0; i < n-1; i++) {
        cout << 0;
    }
    cout << endl;

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