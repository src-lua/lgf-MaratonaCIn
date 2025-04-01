#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

const int MOD = 1e9+7;

ll fexpll(ll a, ll n) {
	ll ans = 1;
	while(n) {
		if(n & 1) ans = (ans * a) % MOD;
		a = (a * a) % MOD;
		n >>= 1;
	}
	return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<vector<ll>> groups;
    vector<vector<int>> negatives;
        
    groups.push_back(vector<ll>());
    negatives.push_back(vector<int>());
    int idx = 0;

    ll x;
    for (int i = 0; i < n; i++) {
        idx++;
        cin >> x;
        if (x == 0) {
            groups.push_back(vector<ll>());
            negatives.push_back(vector<int>());
            idx = 0;
        }
        else {
            groups.back().push_back(x);
            if (x < 0) negatives.back().push_back(idx-1);
        }
    }

    vector<int> possible_answ;
    ll sum;
    ll sum1;
    ll sum2;
    ll sum3;

    for (int i = 0; i < groups.size(); i++) {
        sum = 0;
        if (groups[i].size() == 0) continue;
        
        if (negatives[i].size() % 2 == 0) {
            for (auto e : groups[i]) sum += log2(abs(e));
            possible_answ.push_back(sum);
        }
        else if (negatives[i].size() == 1) {
            sum1 = 0, sum2 = 0, sum3 = 0;
            for (int j = 0; j < negatives[i][0]; j++) sum1 += log2(abs(groups[i][j]));
            for (int j = negatives[i][0] + 1; j < groups[i].size(); j++) sum3 += log2(abs(groups[i][j]));
            
            possible_answ.push_back(sum1);
            possible_answ.push_back(sum3);
            
        }

        else {
            sum1 = 0, sum2 = 0, sum3 = 0;
            for (int j = 0; j <= negatives[i][0]; j++) sum1 += log2(abs(groups[i][j]));
            for (int j = negatives[i][0]+1; j < negatives[i].back(); j++) sum2 += log2(abs(groups[i][j]));
            for (int j = negatives[i].back(); j < groups[i].size(); j++) sum3 += log2(abs(groups[i][j]));
            possible_answ.push_back(sum2+max(sum1, sum3));
        }
    }

    if (possible_answ.size() == 0) cout << 1 << endl;
    else cout << fexpll(2, *max_element(possible_answ.begin(), possible_answ.end())) << endl;

    return 0;
}