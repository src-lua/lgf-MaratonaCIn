#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

pair<int,int> find(map<int, pair<int, deque<int>>>& freq, vector<int>& prefix, int start, int end) {
    int answ = 0;
    int i;

    for (i = start; i < end; i++) {
        if (freq[prefix[i]].first > 1) {
            while (!freq[prefix[i]].second.empty() && freq[prefix[i]].second.front() <= i) {
                freq[prefix[i]].second.pop_front();
                freq[prefix[i]].first--;
            }
            if (freq[prefix[i]].second.empty() || (answ == 0 && freq[prefix[i]].second.front() >= end)) continue;

            pair<int,int> tmp = find(freq, prefix, i+1, freq[prefix[i]].second.front());


            // i = freq[prefix[i]].second.front();
            i = tmp.second;
            
            if (tmp.first >= 1) {
                answ += tmp.first;
                i--;
            }

            else {
                freq[prefix[i]].second.pop_front();
                freq[prefix[i]].first--;
                answ++;
            }
        }
    }

    return {answ, i};
}

int solve() {

    int n; cin >> n;

    map<int, pair<int, deque<int>>> freq;
    
    vector<int> prefix;
    prefix.push_back(0);

    freq[prefix.back()].first++;
    freq[prefix.back()].second.push_back(0);

    int x;

    for (int i = 1; i <= n; i++) {
        cin >> x;

        prefix.push_back(prefix.back() + x);

        freq[prefix.back()].first++;
        freq[prefix.back()].second.push_back(i);
    }

    cout << find(freq, prefix, 0, prefix.size()).first << '\n';

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