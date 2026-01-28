#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    vector<int> arr(n);
    map<int, vector<pii>> pos;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    };

    set<int> sums;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            sums.insert(arr[i] + arr[j]);
            pos[arr[i] + arr[j]].push_back({i+1, j+1});
        }
    }

    for (auto e : sums) {
        if (*sums.lower_bound(x - e) == x - e) {
            int a, b, c, d;

            for (int i = 0; i < pos[e].size(); i++) {
                for (int j = 0; j < pos[x - e].size(); j++) {
                    a = pos[e][i].first;
                    b = pos[e][i].second;
                    c = pos[x - e][j].first;
                    d = pos[x - e][j].second;

                    if (a != b && a != c && a != d && b != c && b != d &&
                        c != d)
                        break;
                }
                if (a != b && a != c && a != d && b != c && b != d && c != d) {
                    cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
                    return 0;
                }
            }
        }

    }


    cout << "IMPOSSIBLE\n";

    return 0;
}