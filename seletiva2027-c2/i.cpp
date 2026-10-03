#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, k; cin >> n >> m >> k;

    vector<int> robots(n), spikes(m);
    for (auto &x : robots) cin >> x;
    for (auto &x : spikes) cin >> x;

    string ops; cin >> ops;
    vector<int> dir(k);
    for (int i = 0; i < k; i++) dir[i] = (ops[i] == 'L' ? -1 : 1);
    vector<int> prefix(k+1);
    for (int i = 0; i < k; i++) prefix[i+1] = prefix[i] + dir[i];

    vector<int> prefix_max(k+1), prefix_min(k+1);
    for (int i = 0; i < k; i++) {
        prefix_max[i+1] = max(prefix_max[i], prefix[i+1]);
        prefix_min[i+1] = min(prefix_min[i], prefix[i+1]);
    }

    sort(robots.begin(), robots.end());
    sort(spikes.begin(), spikes.end());

    vector<int> dist_left(n, INT_MAX), dist_rght(n, INT_MAX);

    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < m && spikes[j] < robots[i]) j++;

        if (j > 0) dist_left[i] = robots[i] - spikes[j-1];
        if (j < m) {
            dist_rght[i] = spikes[j] - robots[i];
            if (spikes[j] == robots[i]) dist_left[i] = 0;
        }
    }

    vector<int> deaths(k+2);
    for (int i = 0; i < n; i++) {
        int left = lower_bound(prefix_min.begin(), prefix_min.end(),
                               -dist_left[i], greater<int>()) - prefix_min.begin();
        int rght = lower_bound(prefix_max.begin(), prefix_max.end(),
                               dist_rght[i]) - prefix_max.begin();
        deaths[min(left, rght)]++;
    }

    int alive = n - deaths[0];
    for (int x = 1; x <= k; x++) cout << (alive -= deaths[x]) << ' ';
    cout << '\n';
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) solve();

    return 0;
}
