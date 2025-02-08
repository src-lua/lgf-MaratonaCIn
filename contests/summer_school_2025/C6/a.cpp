#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using pii = pair<int,int>;

const double PI = 3.1415926535;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << setprecision(16) << fixed;

    int theta, n;
    cin >> theta >> n;
    
    double tg = tan(PI/180 * theta);

    vector<pii> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end());

    double answ = 0.0;
    double curr = 0.0;

    for (int i = 0; i < n; i++) {
        curr = max(curr, double(arr[i].first));
        
        double end = arr[i].first + arr[i].second/tg;

        if (end - curr > 0)
            answ += end - curr;
        
        curr = max(curr, end);
    }

    cout << answ;

    return 0;
}