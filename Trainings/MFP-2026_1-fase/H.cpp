/**
 * Author:      Lua
 * Problem:     H
 * Link:        https://codeforces.com/group/9CNwiex6Ir/contest/530284/problem/H
 * Status:      AC
 * Created:     07-05-2026 19:05:05
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k; cin >> n >> k;

    priority_queue<ll, vector<ll>, greater<ll>> emp_pq;
    for (int i = 0; i < k; i++) emp_pq.push(0LL);

    priority_queue<ll, vector<ll>, greater<ll>> in_store;

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        ll arrival, required_time; cin >> arrival >> required_time;

        ll emp = emp_pq.top(); emp_pq.pop();
        ll finish = max(emp, arrival) + required_time;
        emp_pq.push(finish);
        in_store.push(finish);

        while (!in_store.empty() && in_store.top() <= arrival)
            in_store.pop();

        ans = max(ans, (ll)in_store.size());
    }

    cout << ans << '\n';

    return 0;
}
