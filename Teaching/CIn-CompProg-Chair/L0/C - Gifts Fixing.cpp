#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

int solve() {
    int n; cin >> n;

    vector<int> candies(n);
    vector<int> oranges(n);

    for (int i = 0; i < n; i++) {
        cin >> candies[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> oranges[i];
    }

    int min_candies = *min_element(candies.begin(), candies.end());
    int min_oranges = *min_element(oranges.begin(), oranges.end());

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        arr[i] = max(candies[i]-min_candies, oranges[i]-min_oranges);
    }

    ll answ = 0;

    for (auto e : arr) {
        answ += e;
    }

    cout << answ << endl;

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