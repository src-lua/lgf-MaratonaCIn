/*                                          
  Lucas Guimarães Fernandes </lgf_cin>
  MaratonaCIn @ CIn - UFPE

  [Customer Service](codeforces.com/contest/2059/problem/C)
  Status: Accepted
*/

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int n; cin >> n;
    vector<vector<int>> queues(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> queues[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        reverse(queues[i].begin(), queues[i].end());
    }
    

    for (int i = 0; i < n; i++) {
        sort(queues.rbegin(), queues.rend());
    }

    int answ = 1;
    bool flag = false;
    int k = 0;

    for (int i = 0; i < n; i++) {
        if (queues[i][i-k] != 1) k++;
        else if (queues[i][i-k] == 1) answ++;
        else break;
    }
    
    cout << min(n, answ) << endl;

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