#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    int q; cin >> q;

    int x;
    for (int i = 0; i < q; i++) {
        cin >> x;
        cout << upper_bound(arr.begin(), arr.end(),x) - arr.begin() << '\n';
    }
    
    

    return 0;
}