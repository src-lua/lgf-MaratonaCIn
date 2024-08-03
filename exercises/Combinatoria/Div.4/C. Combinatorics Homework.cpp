#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int m;

    vector<int> arr(3);

    cin >> arr[0] >> arr[1] >> arr[2] >> m;

    sort(arr.begin(), arr.end());

    
    if (arr[0] + arr[1] + arr[2] - 3 >= m && m >= arr[2] - (arr[1] + arr[0] + 1))
        cout << "YES\n";
    else 
        cout << "NO\n";

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