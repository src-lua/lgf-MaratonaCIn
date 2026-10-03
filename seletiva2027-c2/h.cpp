#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> arr(n); for (auto &x : arr) cin >> x;

    vector<int> groups;
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) cnt++;
        else {
            groups.push_back(cnt);
            cnt = 1;
        }
    }
    groups.push_back(cnt);

    int ans = 0;
    for (auto i = 1; i < groups.size(); i++)
        ans = max(ans, 2 * min(groups[i - 1], groups[i]));

    cout << ans << '\n';
    return 0;
}