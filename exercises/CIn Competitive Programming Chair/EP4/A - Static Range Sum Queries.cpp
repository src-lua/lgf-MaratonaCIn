#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;
    vector<ll> arr(n);
    vector<ll> prefix(n+1);
    prefix[0] = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        prefix[i+1] = arr[i]+prefix[i];
    }

    int l, r;
    for (int i = 0; i < q; i++) {
        cin >> l >> r;
        cout << prefix[r]-prefix[l-1] << endl;
    }
    
    return 0;
}