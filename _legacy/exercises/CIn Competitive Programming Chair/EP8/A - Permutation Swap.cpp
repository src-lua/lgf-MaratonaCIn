#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    // Binary Search on answer don't work cause the function that would k-sort
    // the array is not monotonous. Inspired by the k-sort function, we can
    // notice that gcd property.

    int answ = abs(arr[0]-1);
    for (int i = 1; i < n; i++) {
        answ = gcd(answ, abs(arr[i]-(i+1)));
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