/**
 * Author:      Lua
 * Problem:     H
 * Link:        https://codeforces.com/gym/101492/problem/H
 * Status:      ~
 * Created:     01-05-2026 09:34:33
 **/

#include <bits/stdc++.h>

using namespace std;

string dirs = "ESON";
const int dx[] = {1,0,-1,0};
const int dy[] = {0,-1,0,1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int x0, y0, xf, yf; 
    char dir; 
    
    cin >> x0 >> y0 >> dir >> xf >> yf;

    int Dx = xf-x0;
    int Dy = yf-y0;

    int d;
    for (int i = 0; i < 4; i++) 
        if (dirs[i] == dir) d = i;

    vector<string> ans;
    
    while (Dx || Dy) {
        if ((dx[d] > 0 && Dx > 0) || (dx[d] < 0 && Dx < 0)) {
            ans.push_back("A " + to_string(abs(Dx)));
            Dx = 0;
        } else
        if ((dy[d] > 0 && Dy > 0) || (dy[d] < 0 && Dy < 0)) {
            ans.push_back("A " + to_string(abs(Dy)));
            Dy = 0;
        } else {
            ans.push_back("D");
            d += 1; d %= 4;
        }
    }

    cout << ans.size() << '\n';
    for (auto x : ans) cout << x << '\n';

    return 0;
}
