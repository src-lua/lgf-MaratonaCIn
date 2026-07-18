#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    double hc, dc; cin >> hc >> dc;
    double hm, dm; cin >> hm >> dm;
    double k, d, h; cin >> k >> d >> h;

    while(k--) {
        if (ceil((hc+h)/dm) - ceil(hc/dm) > ceil(hm/dc) - ceil(hm/(dc+d))) hc += h;
        else dc += d;
    }

    if (ceil(hc/dm) >= ceil(hm/dc)) cout << "YES\n";
    else cout << "NO\n";

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