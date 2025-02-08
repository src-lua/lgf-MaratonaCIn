/*                                          
  Lucas Guimarães Fernandes </lgf_cin>
  MaratonaCIn @ CIn - UFPE

  [Maximize Mex](codeforces.com/contest/2021/problem/B)
  Status: Accepted
*/

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int n, k; cin >> n >> k;
  
    map<int, int> freq;

    int x;
    for (int i = 0; i < n; i++) {
        cin >> x; freq[x]++;
    }

    int answ = n;

    for (int i = 0; i < n; i++) {
        if (freq[i] == 0) {
            answ = i; break;
        }
        if (freq[i] > 1) {
            freq[i+k] += freq[i]-1;
            freq[i] = 1;
        }
    }

    cout << answ << endl;

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