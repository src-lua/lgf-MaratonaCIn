#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, h; cin >> n >> h;

    vector<int> bot(n/2);
    vector<int> top(n/2);

    for (int i = 0; i < n/2; i++) {
        cin >> bot[i];
        cin >> top[i];
    }

    sort(bot.begin(), bot.end());
    sort(top.begin(), top.end());
    
    map<int,int> m;

    // lower_bound() -> greater or equal
    for (int i = 1; i <= h; i++) {
        int b = n/2 - (lower_bound(bot.begin(), bot.end(), i) - bot.begin());

        int t = n/2 - (lower_bound(top.begin(), top.end(), h-i+1) - top.begin());

        m[t+b]++;
    }

    for (auto [k, v] : m) {
        cout << k << ' ' << v << '\n';
        break;
    }
    

    return 0;
}