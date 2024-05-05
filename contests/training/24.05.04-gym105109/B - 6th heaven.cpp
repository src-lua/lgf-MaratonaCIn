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

ll MOD = 1e9 + 7;

bool ciclo = false;

int bfs_normal(vvi &g, int s, int n, vi &vis) {
    vis[s] = 1;
    int c = 1;

    vi par(n, -1);
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (vis[v] == 0) {
                c++;
                vis[v] = 1; 
                q.push(v);
                par[v] = u;
            } 
            else if (vis[v] == 1 && v != par[u]) {
                vis[v] = 2;
                ciclo = true;
                break;
            }
        }

        if (ciclo) break;
    }

    return c;

}

ll fact(ll n) {
    ll f = 1;
    FOR(i, 2, n+1) {
        f = f*i % MOD;
    }
    return f;
}

ll exp2(int n) {
    ll f = 1;
    FOR(i, 0, n) {
        f = f*2 % MOD;
    }
    return f;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;
    vvi g(n);
    vi grau(n);

    FOR(i, 0, k) {
        int a, b;
        cin >> a >> b;

        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
        grau[a-1]++;
        grau[b-1]++;
        
        if (grau[a-1] >= 3 || grau[b-1] >= 3) {
            ciclo = true;
        }

    }

    vi grupos;
    int d = 0;
    vi vis(n, 0);

    if (!ciclo) {
        FOR(i, 0, n) {
            if (vis[i]) continue;
            int c = bfs_normal(g, i, n, vis);
            if (ciclo) break;

            grupos.push_back(c);
            if (c > 1) d++;
        }
    } 

    if (ciclo) {
        cout << -1 << endll;
    } else {
        ll ans = fact(grupos.size())*(exp2(d)) % MOD;

        cout << ans << endll;
    }

}