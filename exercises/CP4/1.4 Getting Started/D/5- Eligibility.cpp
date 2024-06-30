#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    string s;
    string d1, d2;
    int c;

    cin >> s >> d1 >> d2 >> c;

    if (stoi(d1.substr(0,4)) >= 2010) {
        cout << s << " eligible\n";
        return 0;
    }

    if (stoi(d2.substr(0,4)) >= 1991) {
        cout << s << " eligible\n";
        return 0;
    }

    if (c >= 41) {
        cout << s << " ineligible\n";
        return 0;
    }

    cout << s << " coach petitions\n";
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