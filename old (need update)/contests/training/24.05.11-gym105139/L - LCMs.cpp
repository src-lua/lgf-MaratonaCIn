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

ll lcm(ll a, ll b) {
    return (a*b) / gcd(a,b);
}

vector<pii> getFact(int n){
	vector<pii> primes;
	for(int p = 2; p*p <= n; p++){
		if(n % p == 0){
			int exp = 0;
			while(n % p == 0){
				exp++;
				n /= p;
			}
			primes.push_back({p,exp});
		}
	}
	if(n > 1) primes.push_back({n,1});
	return primes;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        ll a,b; cin >> a >> b;
        ll ans;

        if (gcd(a,b) == a) {
            ans = b;
        } else if (gcd(a,b) != 1) {
            ans = a + b;
        }else {
            vpii aa = getFact(a);
            vpii bb = getFact(b);

            ll f1 = aa[0].first;
            ll f2 = bb[0].first;

            ans = min(lcm(a,f1) + lcm(f1,b), lcm(a,2)+ lcm(2,b));
            ans = min(ans, lcm(a, f2)+ lcm(f2, b));
            ans = min(ans, lcm(a,b));
        }

        cout << ans << endll;
    }

    

}