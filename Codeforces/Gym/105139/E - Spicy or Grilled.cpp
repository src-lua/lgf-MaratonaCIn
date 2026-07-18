#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pll> vpll;
typedef tuple<ll, ll, ll> lll;
typedef tuple<int,int,int> iii;

#define endll '\n';

int INF = INT_MAX;
long long INFF = LLONG_MAX;
int dirx[8] = { -1, 0, 0, 1, -1, -1, 1, 1 };
int diry[8] = { 0, 1, -1, 0, -1, 1, -1, 1 };

#define FOR(i,L,R) for (int i = L; i < R; i++)

#define ALL(c) (c).begin(),(c).end()

void solve(){
    int n, x, a, b; cin >> n >> x >> a >> b;
    cout << x*b + (n-x)*a << '\n';
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }

    

}