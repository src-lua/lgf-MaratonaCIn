/**
 * Author:      Lua
 * Problem:     D
 * Link:        https://codeforces.com/group/9CNwiex6Ir/contest/530284/problem/D
 * Status:      AC
 * Created:     07-05-2026 19:05:05
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<int> perm = {0,1,2,3,4,5};
    vector<vector<ll>> board(6, vector<ll>(6));
    ll ans = 0;

    for (int i = 0; i < 6; i++) for (int j = 0; j < 6; j++) cin >> board[i][j];
    

    do {
        ll curr = 0;
        for (int i = 0; i < 6; i++) {
            curr += board[i][perm[i]];
        }
        ans = max(ans, curr);
        
    } while (next_permutation(perm.begin(), perm.end()));
    
    cout << ans << '\n';
    return 0;
}
