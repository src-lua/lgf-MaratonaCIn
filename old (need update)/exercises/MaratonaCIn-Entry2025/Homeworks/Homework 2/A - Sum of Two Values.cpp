#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x; cin >> n >> x;

    vector<int> arr(n);
    map<int, vector<int>> pos;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        pos[arr[i]].push_back(i+1);
    };

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        auto e = arr[i];
        if (*lower_bound(arr.begin(), arr.end(), x-e) == x-e) {
            if (e != x-e) {
                cout << pos[e][0] << ' ' << pos[x-e][0] << '\n';
                return 0;
            }
            else if (pos[e].size() > 1) {
                cout << pos[e][0] << ' ' << pos[x-e][1] << '\n';
                return 0;   
            }
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}