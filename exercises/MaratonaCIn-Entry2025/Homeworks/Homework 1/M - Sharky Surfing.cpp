#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using pii = pair<int,int>;

int solve() {

    int n, m, l;
    cin >> n >> m >> l;

    vector<pii> hurdles(n);
    vector<pii> powerups(m);

    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        hurdles[i] = {x,y};
    }
    
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        powerups[i] = {x,y};
    }


    int hurdle_index = 0;
    int powerup_index = 0;
    int pos = hurdles[0].first;
    int jump_power = 1;
    int answ = 0;

    priority_queue<int> pq_powerups;

    while (pos < l && hurdle_index < hurdles.size()) {
        while (powerup_index < powerups.size() && pos >= powerups[powerup_index].first) {
            pq_powerups.push(powerups[powerup_index].second);
            powerup_index++;
        }
        
        while ((jump_power <= hurdles[hurdle_index].second - hurdles[hurdle_index].first + 1)) {
            if (pq_powerups.empty()) {
                cout << -1 << '\n';
                return 0;
            }

            answ++;
            jump_power += pq_powerups.top();
            pq_powerups.pop();
        
        }
        hurdle_index++;
        pos = hurdles[hurdle_index].first;
    }

    cout << answ << '\n';
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