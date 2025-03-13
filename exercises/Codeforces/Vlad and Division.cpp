/*                                          
  Lucas Guimarães Fernandes </lgf_cin>
  MaratonaCIn @ CIn - UFPE

  [Vlad and Division](https://codeforces.com/contest/1926/problem/D)
  Rating: 1300
  Tags: xor; bitwise; bitmask; greedy;
  Status: Accepted
*/
#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

int solve() {

    int n; cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    int groups = 0;
    map<ll, int> m;

    for (int i = 0; i < n; i++) {
        if (m[arr[i]] == 0) {
            groups++;
            // a ^ b = k => a ^ k = b 
            m[arr[i] ^ (1ll << 31)-1]++;

        } 
        else {
            m[arr[i]]--;
        }
    }

    cout << groups << endl;

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