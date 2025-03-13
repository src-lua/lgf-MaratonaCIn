#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int n, q; cin >> n >> q;

    vector<int> months(n+n);
    for (int i = 0; i < n; i++) cin >> months[i];

    for (int i = 0; i < n; i++) {
        months[n+i] = months[i];
    }

    vector<int> prefix(n+n+1);
    prefix[0] = 0;

    for (int i = 0; i < n+n; i++) {
        prefix[i+1] = prefix[i] + months[i];
    }
    
    

    int startday, startmonth, endday, endmonth;
    for (int i = 0; i < q; i++) {
        cin >> startday >> startmonth >> endday >> endmonth;

        if (endmonth < startmonth || (endmonth == startmonth && endday < startday)) {
            endmonth += n;
        }

        cout << months[startmonth-1]-startday+1 + prefix[endmonth]-prefix[startmonth]-months[endmonth-1]+endday << endl;    
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