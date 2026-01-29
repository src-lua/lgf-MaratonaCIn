/**
 * Author:      Lua
 * Problem:     M
 * Link:        https://vjudge.net/contest/783478#problem/M
 * Status:      AC
 * Created:     29-01-2026 11:21:13
 **/

#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const int inf = 1e9;
void solve() {
	int d, l; cin >> d >> l;
    double D = d, L = l;

    cout << acos(-1) * (L/2) * sqrtl((L/2)*(L/2)-((D/2)*(D/2))) << '\n';

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
	// freopen("in.txt", "r", stdin);
    cout << setprecision(3) << fixed;
    int tc; cin >> tc; while(tc--) solve();
    return 0;
}
