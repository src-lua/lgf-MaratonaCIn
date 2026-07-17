/**
 * Author:      Lua
 * Problem:     D
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/103049/problem/D
 * Status:      ~
 * Created:     12-07-2026 09:01:59
 **/

#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using ld = long double;
using cord = pair<int,int>;

const int dx[8] = {-1,-1,-1, 0, 1, 1, 1, 0};
const int dy[8] = {-1, 0, 1, 1, 1, 0,-1,-1};

bool TEST = false;
vector<cord> STARS;
int N;

auto seed = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(seed);

int uniform(int l, int r) {
  uniform_int_distribution<int> uid(l, r);
  return uid(rng);
}

const int MX_CORD = 1e6;
int QUERYS = 0;

void gen() {
    N = uniform(7, 7);
    for (int i = 0; i < N; i++) {
        STARS.push_back({uniform(0, 1e6), uniform(0, 1e6)});
    }
}

void print_board() {
    int n = 7;

    vector<vector<ll>> board(n, vector<ll>(n));

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        ll dist = INT_MAX;

        for (auto [x,y] : STARS) {
            dist = min(dist, (ll)round(hypot(abs(x-i), abs(y-j))*hypot(abs(x-i), abs(y-j))));
        }
        
        board[i][j] = dist;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
}

ll ans_guess(int x, int y) {
    ll dist = LLONG_MAX;

    for (auto [i,j] : STARS) {
        dist = min(dist, (ll)round(hypot(abs(x-i), abs(y-j))*hypot(abs(x-i), abs(y-j))));
    }

    return dist;
} 

int ans_n() {
    return N;
}

ll guess(int x, int y) {
    QUERYS++;
    
    ll ans; 
    if (!TEST) {
        cout << x << ' ' << y << endl;
        cin >> ans;
    } else {
        ans = ans_guess(x, y);
        if(ans == 0) STARS.erase(find(STARS.begin(), STARS.end(), cord{x, y}));
    }
    return ans;
}

inline bool is_valid(int x, int y) {
    return (x >= 0 && y >= 0 && x <= MX_CORD && y <= MX_CORD);
}

pair<ll, int> find_dir(int x, int y) {
    vector<pair<ll,int>> dirs;

    for (int d = 0; d < 8; d++) {
        int i = x + dx[d], j = y + dy[d];
        if (!is_valid(i,j)) continue;
        dirs.emplace_back(guess(i,j), d);
    }

    sort(dirs.begin(), dirs.end());
    return *dirs.begin();
} 

signed main() {
    ios::sync_with_stdio(false);

    if (TEST) gen();

    int n; if (!TEST) cin >> n; else n = ans_n();

    cord curr = {MX_CORD/2, MX_CORD/2};

    while(n) {
        auto [x,y] = curr;
        ll ans = guess(x, y);
        if (ans == 0) {
            n--; continue;
        }
        auto [sqr_dist, dir] = find_dir(x,y);
        ll dist = sqrtl(ans);

        ll i = x + dist * dx[dir], j = y + dist * dy[dir];
        i = clamp(i, 0ll, MX_CORD), j = clamp(j, 0ll, MX_CORD);

        curr = {i, j};
    }


    if (TEST) {
        assert(STARS.size() == 0);
        cout << "TEST ENDED! \n";
        cout << QUERYS << " querys used.\n";
    }

    return 0;
}