#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int n, m; cin >> n >> m;
    vector<char> arr(n+m);

    for (int i = 0; i < n+m; i++) cin >> arr[i];

    reverse(arr.begin()+n, arr.end());
    
    char prev = ' ';
    bool flag = false;

    for(auto e : arr) {
        if (e == prev) {
            if (flag) {
                cout << "NO" << endl;
                return 0;
            }
            flag = true;
        }
        prev = e;
    }
    
    cout << "YES" << endl;
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