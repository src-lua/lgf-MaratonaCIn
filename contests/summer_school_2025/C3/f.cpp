#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;
using pii = pair<ll,ll>;

bool f_compare(const pii& l, const pii& r) { return l.first < r.first; }
bool s_compare(const pii& l, const pii& r) { return l.second < r.second; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    ll a = 0, b = 0;

    vector<pii> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
        a += arr[i].first;
        b += arr[i].second;
    }

    if (n % 2 != 0) {
        cout << "impossible\n"; 
        return 0;
    }
    n/=2;

    if (a % n != 0 || b % n != 0) {
        cout << "impossible\n"; 
        return 0;
    }

    a /= n, b /= n;

    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++) {
        auto [x, y] = arr[i];
        pii v = {a-x, b-y};

        auto lb = lower_bound(arr.begin()+i, arr.end(), v, f_compare);
        auto ub = upper_bound(arr.begin(), arr.end(), v, f_compare);

        if (lb->first != v.first) {
            cout << "impossible\n";
            return 0;
        }

        auto sub = upper_bound(lb,ub,v,s_compare)-1;

        if (sub->second != v.second) {
            cout << "impossible\n";
            return 0;
        }

        arr.erase(sub);
    }

    cout << "possible";

    return 0;
}