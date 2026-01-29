/**
 * Author:      Lua
 * Problem:     I
 * Link:        https://vjudge.net/contest/784977#problem/I
 * Status:      AC
 * Created:     28-01-2026 16:28:16
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<int,int>;

const bool TEST = false;

int nnn = 16, mmm = 16;
pii xxxx = {3, 9}, yyyy = {9, 3};

int dist(pii a, pii b) {
    return abs(a.first-b.first) + abs(a.second-b.second);
}

vector<vector<int>> board;

void RUN_TEST(int n, int m){    
    board = vector<vector<int>>(n, vector<int>(m, -1));
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            board[i][j] = dist(xxxx, {i,j}) + dist(yyyy, {i,j});
        }
    }
}

int scan(int x, int y) {
    x++, y++;
    cout << "SCAN " << x << ' ' << y << endl;
    if(TEST) return board[x-1][y-1];
    int ans; cin >> ans;
    return ans;
}

int dig(int x, int y) {
    x++, y++;
    cout << "DIG " << x << ' ' << y << endl;
    if(TEST){
        if(pii(x-1, y-1) == xxxx || pii(x-1, y-1) == yyyy) return 1;
        return 0;
    } 
    int ans; cin >> ans;
    return ans;
}

void solve() {
    int n, m; 
    if(TEST) { n = nnn; m = mmm; RUN_TEST(n, m); }
    else cin >> n >> m;
    
    // (r1 + r2) + (c1 + c2)
    int a = scan(0, 0);
    
    // (r1 + r2) + (m-1-c1 + m-1-c2)
    int b = scan(0, m - 1);
    
    // a + b = 2*Sr + 2*(m-1)
    ll sr = (1LL * a + b - 2LL * (m - 1)) / 2;
    ll sc = a - sr;
    
    ll delta_r = scan(sr/2, 0) - sc;
    ll delta_c = scan(0, sc/2) - sr;
    
    int r1 = (sr - delta_r) / 2;
    int r2 = (sr + delta_r) / 2;
    
    int c1 = (sc - delta_c) / 2;
    int c2 = (sc + delta_c) / 2;
    
    if (dig(r1, c1)) {
        dig(r2, c2);
    } 
    else {
        dig(r1, c2);
        dig(r2, c1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    
    if (TEST) solve();
    else {
        int tc; cin >> tc; 
        while (tc--) solve();
    }

    return 0;
}