#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int n, q; cin >> n >> q;
    vector<int> arr(n);
    vector<int> prefix(n+1);
    prefix[0] = 0;

    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.rbegin(), arr.rend());
    
    for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + arr[i];

    int x;
    for (int i = 0; i < q; i++) {
        cin >> x;
        auto l = lower_bound(prefix.begin(), prefix.end(), x);

        if (l != prefix.end() && *l >= x) {
            cout << l - prefix.begin() << '\n';
        }
        else {
            cout << -1 << '\n';
        }
    }
    

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