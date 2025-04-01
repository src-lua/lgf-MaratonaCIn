#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;
using pii = pair<ll,ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, k; cin >> n >> k;

    map<string, ll> atr;

    string s; ll x;
    
    for (ll i = 0; i < n; i++) {
        cin >> s >> x;

        atr[s] = x;
    }

    ll m; cin >> m;

    ll score = 0;

    map<string, pii> events;
    map<string, ll> thress;

    ll mx = 0;

    for (ll i = 0; i < m; i++) {
        cin >> s >> x;

        if (x < events[s].second) thress[s]++;
        else if (x > events[s].second) thress[s] = events[s].first;

        events[s].first++;
        
        events[s].second = max(x, events[s].second);

        mx = max(mx, events[s].first);
    }

    vector<ll> nsei;

    for (auto [attribute, features] : events) {
        auto [ammount, threshold] = features;

        if (atr[attribute] > threshold) {
            score += ammount * atr[attribute];
            continue;
        }

        if (atr[attribute] < threshold) {
            k -= abs(threshold-atr[attribute]);
            atr[attribute] = threshold;

            if (k < 0) {
                cout << 0 << endl;
                return 0;
            }
        }

        nsei.push_back((ammount-thress[attribute])*(atr[attribute]+1)+(thress[attribute]));
    }

    for (auto [attribute, value] : thress) {
        score += value * atr[attribute];
    }

    sort(nsei.rbegin(), nsei.rend());

    for (auto e : nsei) {
        if (k <= 0) break;
        if (e < mx) break;
        k--;
        score += e;
    }

    score += k * mx;

    cout << score << endl;
    
    return 0;
}