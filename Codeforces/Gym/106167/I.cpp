/**
 * Author:      Lua
 * Problem:     I
 * Link:        https://codeforces.com/gym/106167/problem/I
 * Status:      ~
 * Tags:        
 * Created:     22-07-2026 08:28:05
 **/

#include <bits/stdc++.h>

using namespace std;

bool solve(int idx, vector<int>& curr, vector<int>& sol,
           vector<vector<vector<int>>>& f, int n, int m,
           vector<vector<vector<bool>>>& visited) {
    if (idx >= curr.size()) {
        return f[curr[0]][curr[1]][curr[2]] == sol[1] &&
               f[curr[n-1]][curr[0]][curr[1]] == sol[0] &&
               f[curr[n-2]][curr[n-1]][curr[0]] == sol[n-1];
    }

    int u = curr[idx-2], v = curr[idx-1];
    
    if (visited[idx][u][v]) return false;

    for (int k = 1; k <= m; k++) {
        if (f[curr[idx-2]][curr[idx-1]][k] == sol[idx-1]) {
            curr[idx] = k;
            if (solve(idx+1, curr, sol, f, n, m, visited)) return true;
        }
    }
    visited[idx][u][v] = true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<vector<int>>> f(m+1, vector<vector<int>>(m+1, vector<int>(m+1)));
    for (int i = 1; i <= m; i++) for (int j = 1; j <= m; j++) for (int k = 1; k <= m; k++)
    cin >> f[i][j][k];
    
    vector<int> sol(n); for (auto &x : sol) cin >> x;
    
    for (int i = 1; i <= m; i++) for (int j = 1; j <= m; j++) {
        vector<int> chute(n);
        chute[0] = i; chute[1] = j;
        vector<vector<vector<bool>>> visited(n+1, vector<vector<bool>>(m+1, vector<bool>(m+1, false)));
        if (solve(2, chute, sol, f, n, m, visited)) goto end;
    }
    
    cout << "NO\n";
    return 0;
    end:
    cout << "YES\n";
    return 0;
}
