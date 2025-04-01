#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<int> arr(n-1);

    for (int i = 0; i < n-1; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    for (int i = 1; i <= n; i++) {
        if (i != *lower_bound(arr.begin(), arr.end(), i)) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}