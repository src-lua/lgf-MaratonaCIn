#include <bits/stdc++.h>

#define endl '\n'
#define int long long

using namespace std;

// Time Complexity: O(log(n))
int binarySearch(int l, int r, int target) {
    int answ;
    while (l <= r) {
        int m = l + (r - l) / 2;
 
        // If NOT SOLVE, ignore left half
        if (! (m*m + m > target) )
            l = m + 1;
 
        // If SOLVE, ignore right half
        else {
            answ = m;
            r = m - 1;
        }
    }
 
    return answ-1;
}

int solve() {

    int n, m; cin >> n >> m;

    int k = abs(n-m);

    cout << binarySearch(0, m, 2*k) + 1 << '\n';

    // n(n+1) == (k * 2)

    return 0;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}