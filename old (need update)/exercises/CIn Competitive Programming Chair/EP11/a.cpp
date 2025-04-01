#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    set<int> area;

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            // |x1(y2-y3) + x2(y3-y1) + x3(y1-y2)| / 2
            area.insert((arr[i] - arr[j]));
        }
    }

    cout << area.size() << endl;
    

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