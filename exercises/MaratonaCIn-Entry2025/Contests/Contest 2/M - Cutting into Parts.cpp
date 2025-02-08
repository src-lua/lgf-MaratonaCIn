#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<int> arr;

    for (int i = 1; i*i <= n; i++) {
        int k = n/i;
        if (i * k == n) {
            arr.push_back(i+k);
        }
    }

    cout << *min_element(arr.begin(), arr.end()) -2 << endl;

    return 0;
}