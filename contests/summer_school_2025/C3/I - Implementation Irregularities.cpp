#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using pii = pair<int,int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<pii> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i].second;
    for (int i = 0; i < n; i++) cin >> arr[i].first;
    
    sort(arr.begin(), arr.end());

    int curr_time = 0;
    int pc = 1;

    for (auto [curr, expected] : arr) {
        if (curr == -1) continue;

        curr_time += expected;
        pc = max(pc, (curr_time-1)/curr + 1);
    }

    cout << pc << endl;

    return 0;
}