#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int prev = 0;

    ll answ = 0;

    for (auto e : arr) {
        if (e < prev) {
            answ += prev-e;
        }
        else {
            prev = e;
        }

    }

    cout << answ << endl;    

    return 0;
}