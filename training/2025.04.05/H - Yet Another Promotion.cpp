#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    long long int a, b; cin >> a >> b;
    long long int n, m; cin >> n >> m;
    
    if (a < b) {
        cout << ((n)/(m+1ll)) * a * m + (n%(m+1ll)) * a << '\n';
    }

    else if ((m+1)*b <= m*a) {
        cout << n*b << '\n';
    }

    else {
        cout << ((n)/(m+1ll)) * a * m + (n%(m+1ll)) * b << '\n'; 
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