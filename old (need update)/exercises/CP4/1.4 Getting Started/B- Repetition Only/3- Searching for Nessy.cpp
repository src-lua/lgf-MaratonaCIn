#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int n, m; cin >> n >> m;

    cout << (long long) ceil((float)(n-2) / 3.0f) * (long long) ceil((float)(m-2) / 3.0f) << '\n';

    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

int tc; cin >> tc; while (tc--) {
    solve();
}

    return 0;
}