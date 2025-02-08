#include <bits/stdc++.h>

#define endl '\n'

using namespace std;


int solve() {

    int n, m, q;
    cin >> n >> m >> q;
    
    vector<int> arr(m);

    int u, v, w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;

        arr.push_back(w);
    }

    auto new_end = unique(arr.begin(), arr.end());

    sort(arr.begin(), new_end);

    for (int i = 0; i < q; i++) {
    
        cin >> u >> v >> w;

        cout << binary_search()
    }
    


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