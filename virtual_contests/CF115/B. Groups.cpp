#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int n; cin >> n;

    int a,b,c,d,e;

    map<int,int> can_attend;

    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c >> d >> e;

        if (a) can_attend[0] += 1;
        if (b) can_attend[1] += 1;
        if (c) can_attend[2] += 1;
        if (d) can_attend[3] += 1;
        if (e) can_attend[4] += 1;
    }


    c = 0;
    for (int i = 0; i < 5; i++) {
        if (can_attend[i] >= n/2) c++;
    }

    if (c >= 2) cout << "YES" << endl;
    else cout << "NO" << endl;
    
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


// TEST CASE THAT BREAKS:
// 1
// 4
// 1 0 0 0 0
// 1 0 1 0 0
// 0 0 1 0 0
// 0 0 0 0 1