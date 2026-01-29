/**
 * Author:      Lua
 * Problem:     B
 * Link:        https://vjudge.net/contest/783478#problem/B
 * Status:      AC
 * Created:     29-01-2026 11:21:13
 **/

#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define vii vector<pii>
using namespace std;
const int inf = 1e9;
void solve() {
		int n; cin >> n;
		vii a(n);

	for(auto &[l,r] : a) cin >> l >> r;

	auto cmp = [&](pii & a , pii & b){
		if(a.second == b.second){
			return a.first < b.first;
		}
		return a.second < b.second;
	};
	sort(a.begin(),a.end(),cmp);

	int ans = 0;
	int curr = 0;
	for(auto [l,r] : a){

		if(l < curr) continue;

		ans++;
		curr = r;

	}

	cout << ans << endl;

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
	// freopen("in.txt", "r", stdin);
	solve();
    return 0;
}
