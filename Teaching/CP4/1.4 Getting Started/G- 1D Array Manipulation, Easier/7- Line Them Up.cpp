#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<string> v(n);
    vector<string> increasing(n);
    vector<string> decreasing(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        increasing[i] = v[i];
        decreasing[i] = v[i];
    }

    sort(increasing.begin(), increasing.end());
    sort(decreasing.rbegin(), decreasing.rend());

    if (v == increasing) {
        cout << "INCREASING" << endl;
    } else if (v == decreasing) {
        cout << "DECREASING" << endl;
    } else {
        cout << "NEITHER" << endl;
    }

    return 0;
}