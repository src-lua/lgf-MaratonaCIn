#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    vector<vector<string>> v(101); 
    int maxv = 0;

    string s; int x;

    for (int i = 0; i < 10; i++) {
        cin >> s >> x;
        v[x].push_back(s);
        maxv = max(maxv, x);
    }

    for (auto e: v[maxv]) {
        cout << e << endl;
    }
    

    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c = 0;
    int tc; cin >> tc; while (tc--) {
        cout << "Case #" << ++c << ":" << endl;
        solve();
    }

    return 0;
}