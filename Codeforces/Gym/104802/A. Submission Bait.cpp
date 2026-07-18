#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int n; cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int r=n-1, l=0;
    int c = 0;

    while(1) {

        if (v[l] == v[r]) {
            l++; r--;
        }

        else if (v[l] > v[r]) {
            v[l] -= v[r];
            r--;
            c++;
        }

        else if (v[l] < v[r]) {
            v[r] -= v[l];
            l++;
            c++;
        }

        if (l >= r) {
            break;
        }
    }

    cout << c << endl;

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