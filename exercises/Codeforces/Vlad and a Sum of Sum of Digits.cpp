/*                                          
  Lucas Guimarães Fernandes </lgf_cin>
  MaratonaCIn @ CIn - UFPE

  [Vlad and a Sum of Sum of Digits](https://codeforces.com/contest/1926/problem/C)
  Rating: 1200
  Tags: Brute Force; Memoization; DP;
  Status: Accepted
*/
#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

vector<int> answ(2e5+1);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = 2e5;

    answ[0] = 0;

    for (int i = 1; i <= n; i++) {
        int e = i;
        int k = 0;
        while(e/10) {
            k += e%10;
            e /= 10;
        }
        k += e;
        
        answ[i] = answ[i-1] + k;
    }

    int t; cin >> t;
    while(t--) {
        int r; cin >> r;
        cout << answ[r] << endl;
    }

    return 0;
}