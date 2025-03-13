/*                                          
  Lucas Guimarães Fernandes </lgf_cin>
  MaratonaCIn @ CIn - UFPE

  [The Trail](https://codeforces.com/contest/2055/problem/C)
  Rating: 1400
  Tags: Constructive; Matrix;
  Status: Accepted
*/
#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

int solve() {

    int n, m; cin >> n >> m;
    string s; cin >> s;

    vector<vector<ll>> mat(n, vector<ll>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    vector<ll> row(n, 0);
    vector<ll> col(m, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            row[i] += mat[i][j];
        }
    }

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            col[j] += mat[i][j];
        }
    }

    int i = 0;
    int j = 0;

    for (int idx = 0; idx < n+m-2; idx++) {
        if (s[idx] == 'D') {
            mat[i][j] = -row[i];

            row[i] += mat[i][j];
            col[j] += mat[i][j];
            
            i++;
        }
        
        else if (s[idx] == 'R') {
            mat[i][j] = -col[j];
            
            row[i] += mat[i][j];
            col[j] += mat[i][j];

            j++;
        }
    }

    mat[n-1][m-1] = -row[n-1];

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cout << mat[i][j] << ' ';
        }
        cout << endl;
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