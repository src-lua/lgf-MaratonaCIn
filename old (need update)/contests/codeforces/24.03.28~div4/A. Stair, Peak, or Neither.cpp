#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int a, b, c; cin >> a >> b >> c;

    if (a<b && b<c) {
        cout << "STAIR" << endl;
    }

    else if (a<b && b>c) {
        cout << "PEAK" << endl;
    }

    else {
        cout << "NONE" << endl;
    }

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