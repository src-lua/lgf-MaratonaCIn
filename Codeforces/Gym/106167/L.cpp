/**
 * Author:      Lua
 * Problem:     L
 * Link:        https://codeforces.com/gym/106167/problem/L
 * Status:      ~
 * Tags:        
 * Created:     22-07-2026 08:28:05
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int MAPPING[256] = {0};
const int WALDO = 62;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    MAPPING['W'] = 1; MAPPING['A'] = 2; MAPPING['L'] = 3; 
    MAPPING['D'] = 4; MAPPING['O'] = 5;

    int n, m; cin >> n >> m;
    vector<vector<int>> board(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c; int k = MAPPING[c];
            if(k) board[i][j] = (1 << k);
        }
    }

    if(n > m) {
        swap(n, m);
        vector<vector<int>> t(n, vector<int>(m));
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
            t[i][j] = board[j][i];
        board = move(t);
    }
    
    const int BITS = 6;
    vector<vector<vector<int>>> prefix(BITS, vector<vector<int>>(n+1, vector<int>(m+1, 0)));
    for (int b = 1; b < BITS; b++)
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
            prefix[b][i+1][j+1] = prefix[b][i][j+1] + prefix[b][i+1][j] - prefix[b][i][j] + ((board[i][j] >> b) & 1);

    auto query = [&](int r1, int c1, int r2, int c2) -> int {
        int res = 0;
        for (int b = 1; b < BITS; b++) {
            int cnt = prefix[b][r2+1][c2+1] - prefix[b][r1][c2+1] - prefix[b][r2+1][c1] + prefix[b][r1][c1];
            if (cnt > 0) res |= (1 << b);
        }
        return res;
    };

    ll ans = LLONG_MAX;

    for (int i = 0; i < n; i++) for (int j = i; j < n; j++) {
        int L = 0, R = 0;
        while (L < m) {
            while (R < m && query(i, L, j, R) != WALDO) R++;
            if (R == m) break; 
            ans = min(ans, ll(j - i + 1) * (R - L + 1));
            L++; 
        }
    }
    
    cout << (ans != LLONG_MAX ? to_string(ans) : "impossible") << '\n';
    
    return 0;
}
