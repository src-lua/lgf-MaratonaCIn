#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> arr(2e5+1);


bool f (int l, int r, vector<ll>& prefix) {
    ll answ = 0;

    cout << "? " << r - l + 1 << ' ';
    for (int i = l; i <= r; i++) {
        cout << i+1 << ' ';
    }
    cout << endl;


    cin >> answ;
    return prefix[r+1] - prefix[l] == answ;
    
}

// Time Complexity: O(log(n))
int binarySearch(int l, int r, vector<ll>& prefix) {
    int answ;
    while (l <= r) {
        int m = l + (r - l) / 2;

        // If NOT SOLVE, ignore left half
        if ((f(l ,m, prefix)) )
            l = m + 1;

        // If SOLVE, ignore right half
        else {
            r = m - 1;
            answ = m;
        }
    }

    return answ;
}

int solve() {

    int n; cin >> n;
    vector<ll> prefix(n+1);
    prefix[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        prefix[i+1] = prefix[i] + arr[i];
    }

    auto answ = binarySearch(0, n-1, prefix) + 1;

    cout << "! " << answ << endl;
    
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