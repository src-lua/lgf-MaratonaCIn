#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;

    vector<int> arr(n+1, 0);

    int x;
    int max_index = 0;

    for (int i = 0; i < m; i++) {
        cin >> x;

        arr[x]++;

        if (arr[x] >= arr[max_index]) {
            if (arr[x] != arr[max_index] || x < max_index)
                max_index = x;
        }

        cout << max_index << '\n';

    }
    

    return 0;
}