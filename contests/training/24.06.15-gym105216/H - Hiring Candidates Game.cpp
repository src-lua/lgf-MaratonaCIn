#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> lll;
typedef tuple<int,int,int> iii;

#define endll '\n';

int INF = INT_MAX;
long long INFF = LLONG_MAX;
int dirx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
int diry[8] = {0, 1, -1, 0, -1, 1, -1, 1};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, r, c; cin >> n >> r >> c;

    set<int> game;

    for (int i = 1; i <= n; i++) {
        game.insert(i);
    }
    auto s1 = game.begin();
    auto s2 = prev(game.end());

    vector<int> hired;

    while (game.size() > 2) {
        int c1 = distance(s1, prev(game.end()));
        if (c1 < r-1) {
            int step = (r-1 - c1) % game.size();
            if (step != 0) s1 = next(game.begin(), step-1);
        } else {
            s1 = next(s1, r-1);
        }

        int c2 = distance(game.begin(), s2);
        if (c2 < c-1) {
            int step = (c-1 - c2) % game.size();
            if (step != 0) s2 = prev(game.end(), step);
        } else {
            s2 = prev(s2, c-1);
        }

        if (s1 == s2) {
            hired.push_back(*s1);
            if (s1 != prev(game.end())) {
                s1 = next(s1);
                game.erase(prev(s1));
                if (s1 == game.end()) s1 = game.begin();
            } else {
                s1 = game.begin();
                game.erase(prev(game.end()));
            }

            if (s1 != game.begin()) {
                s2 = prev(s1);
            } else {
                s2 = prev(game.end());
            }

            
        }
        else {
            if (s2 != game.begin()) {
                s2 = prev(s2);
                game.erase(next(s2));
            } else {
                s2 = prev(game.end());
                game.erase(game.begin());
            }

            if (s1 != prev(game.end())) {
                s1 = next(s1);
                game.erase(prev(s1));
                if (s1 == game.end()) s1 = game.begin();
            } else {
                s1 = game.begin();
                game.erase(prev(game.end()));
            }
        }

    }

    for (auto s : game) {
        hired.push_back(s);
    }

    sort(hired.begin(), hired.end());

    for (int i = 0; i < hired.size()-1; i++) {
        cout << hired[i] << " ";
    }
    cout << hired[hired.size()-1] << endll;

}
