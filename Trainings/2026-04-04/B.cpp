/**
 * Author:      Lua
 * Problem:     B - Baklava Tray
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/101991/problem/B
 * Status:      AC
 * Created:     04-04-2026 14:08:17
 **/

#include <bits/stdc++.h>

using namespace std;
using ld = long double;

ld to_rad(ld x) {
    return acos(-1)*x/180;
}

void solve() {
    int n; cin >> n;
    
    ld l = sqrt(2.0*sin(to_rad(360.0/n)) / (n*sin(to_rad((n-2.0)*180.0/(2.0*n)))*sin(to_rad((n-2.0)*180.0/(2.0*n)))));
    ld a = ((l/2.0) * sin(to_rad((n-2.0)*180.0/(2.0*n)))) / sin(to_rad(360.0/(2.0*n)));
    
    ld ans = 1.0;
    ld prev = -1;

    while (abs((prev) - (ans)) > 1e-12) {
        prev = ans;
        l = l*sin(to_rad(((n-2.0)*180.0)/(n))) / (2.0 * sin(to_rad(  (180.0 - (((n-2.0)*180.0)/n)) / 2.0 )));
        a = ((l/2.0) * sin(to_rad(((n-2.0)*180.0)/(2.0*n)))) / sin(to_rad(360.0/(2*n)));
        ans = ans + (n*l*a/2.0);
    }
 
    cout << ans * 10000 << '\n';
}
    
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cout << setprecision(5) << fixed;
    
    freopen("baklava.in", "r", stdin);
    
    int tc; cin >> tc; while (tc--) solve();
    
    return 0;
}