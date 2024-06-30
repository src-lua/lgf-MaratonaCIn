#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int n; cin >> n;

    int answ = ((n%2)+2)%2;

    if (answ) cout << n << " is odd\n";
    else cout << n << " is even\n";

    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}