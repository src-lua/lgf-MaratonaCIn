/**
 * Author:      Lua
 * Problem:     A
 * Link:        https://vjudge.net/contest/782309#problem/A
 * Status:      AC
 * Created:     29-01-2026 11:06:02
 **/

#include <bits/stdc++.h>
#define endl '\n'
using ll = long long;
using namespace std;

using pii = pair<int,int>;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);

    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    arr.push_back(0);

    stack<pii> stk;

    int ans = 0;
    for (int i = 0; i < n+1; i++) {
        int last_i = -1;
        while(!stk.empty() && stk.top().first > arr[i]) {
            ans = max(min(stk.top().first, i-stk.top().second), ans);
            last_i = stk.top().second;
            stk.pop();
        }
        if (last_i != -1) stk.push({arr[i], last_i});
        stk.push({arr[i], i});

    }

    cout << ans << endl;

}