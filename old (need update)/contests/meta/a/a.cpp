#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using pii = pair<int,int>;

int solve() {

    int n; cin >> n;

    vector<pii> arr(n);

    int a, b;

    bool hasansw = true;
    double answ = 0.0; 

    for (int i = 0; i < n; i++) {
        cin >> a >> b;

        arr[i] = {a,b};
        
        if (i != 0) if (arr[i-1].first >= arr[i].second) {
            hasansw = false;
        }

        answ = max(answ, double(i+1)/double(b));
    }

    if (hasansw) cout << answ << '\n';
    else cout << -1 << '\n'; 

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);

    int c = 0;

    int tc; cin >> tc; while (tc--) {
        cout << "Case #" << ++c << ": "; 
        solve();
    }

    return 0;
}