#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int n; cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(),arr.end());

    int mid;

    if (n% 2==0) mid = n/2 -1;
    else mid = (n+1)/2 -1;

    int mid_val = arr[mid];

    int reps = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == mid_val) reps++;
        if (i == mid+1) reps = 2;
        if (arr[i] > mid_val ) break;
    }

    if (arr[mid+1] == arr[mid]) cout << reps << endl;
    else cout << 1 << endl;
    
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