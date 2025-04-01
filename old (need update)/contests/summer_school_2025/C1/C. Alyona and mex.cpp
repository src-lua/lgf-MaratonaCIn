#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;
using pii = pair<ll,ll>;
using pipii = pair<ll,pii>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    ll left, right;

    vector<pipii> intervals;
    for (int i = 0; i < q; i++) {
        cin >> left >> right;

        intervals.push_back({right-left+1, {left, right} });
    }

    sort(intervals.begin(), intervals.end());

    ll minsz = intervals[0].first;

    cout << minsz << endl;
    for (int i = 0; i < n; i++) {
        cout << i%minsz << ' ';
    } cout << endl;
    
    return 0;
}