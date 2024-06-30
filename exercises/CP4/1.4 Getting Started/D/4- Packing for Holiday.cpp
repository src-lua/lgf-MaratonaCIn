#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int a, b, c; cin >> a >> b >> c;

    if (a <= 20 && b <= 20 && c <= 20) cout << "good\n";
    else cout << "bad\n";

    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c = 0;
    int tc; cin >> tc; while (tc--) { 
        cout << "Case " << ++c << ": ";
        solve();
    }

    return 0;
}