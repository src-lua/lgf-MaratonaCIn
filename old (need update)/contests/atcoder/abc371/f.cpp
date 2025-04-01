#include <bits/stdc++.h>

#define endl '\n'
#define int long long

using namespace std;
using ll = long long;


int binarySearch(int l, int r, vector<ll>& arr, int target) { 
    int answ = -1;
    while (l <= r) {
        int m = l + (r - l) / 2;
 
        // If NOT SOLVE, ignore left half
        if (! (arr[m] > target) )
            l = m + 1;
 
        // If SOLVE, ignore right half
        else {
            r = m - 1;
            answ = m;
        }
    }
    if (answ == -1) answ = r;

    return answ;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<ll> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll sum = 0;

    int q; cin >> q;

    int a, x;


    for (int i = 0; i < q; i++) {
        cin >> a >> x;
    
        if (arr[a-1] < x) {
            int bound = binarySearch(0, arr.size(), arr, x);

            for (int j = a; j <= bound; j++) {
                sum += x + j - a - arr[j-1];
                arr[j-1] = x + j - a;
            }
        }
        else {
            int bound = binarySearch(0, arr.size(), arr, x);

            for (int j = a; j > bound; j--) {
                sum += arr[j-1] - (x + j - a);
                arr[j-1] = x + j - a;
            }
        }

    }

    cout << sum << endl;

    return 0;
}