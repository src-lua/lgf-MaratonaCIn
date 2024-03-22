#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

#define int long long //change main to int32_t


int solve() {

    int n; cin >> n;

    vector<int> arr(n);
    ll sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    if ((sum*2)%n != 0) return 0;

    ll media2 = ((sum*2)/n);

    int c = 0;

    // for (int i = 0; i < n; i++) {        // linear
    //     for (int j = i+1; j < n; j++) {
    //         if (arr[i]+arr[j] == media2) c++;
    //     }
    // }

    sort(arr.begin(),arr.end());

    for (int i = 0; i < n; i++) {       // log
        int val = media2-arr[i];

        int lower = lower_bound(arr.begin()+i+1, arr.end(), val) - arr.begin();
        int upper = upper_bound(arr.begin()+i+1, arr.end(), val) - arr.begin();

        c += upper-lower;
    }

    return c;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        cout << solve() << endl;
    }

    return 0;
}