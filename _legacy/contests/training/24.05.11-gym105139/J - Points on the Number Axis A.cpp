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

ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

// inverso modular de a

int mod = 998244353;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n; cin >> n;
    ll sum = 0;
    FOR(i, 0, n) {
         int x; cin >> x;
         sum += x;
    }
    
    sum%=mod;

    ll a = sum / (gcd(sum,n));
    ll b = n / (gcd(sum,n));

    ll inv, y;
    ll g = gcd(b,mod,inv,y);
    inv = (inv % mod + mod) % mod;

    ll ans = (inv*a) % mod;

    cout << ans << endll;
}