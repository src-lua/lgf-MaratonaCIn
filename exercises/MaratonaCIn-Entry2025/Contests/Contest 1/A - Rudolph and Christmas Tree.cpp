#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {
    int n, d, h; 
    cin >> n >> d >> h;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    arr.push_back(arr.back()+h+1);

    double answ = 0.0;
    int x;

    for (size_t i = 0; i < arr.size()-1; i++) {
        x = (min(h, arr[i+1] - arr[i]));
        answ += (d + d - (x* ((double)(d)/(double)(h)) ) ) * ((double)x / 2.0);
    }
    
    cout << answ << endl;

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << setprecision(9) << fixed;

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}