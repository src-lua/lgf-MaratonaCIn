#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, t, p; 
    cin >> n >> t >> p;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.rbegin(), arr.rend());
    
    cout << max(0, t - arr[p-1]) << endl;

    return 0;
}