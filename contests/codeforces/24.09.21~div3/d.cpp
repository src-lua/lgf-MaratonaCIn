#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

// Lazy SegTree
const int mx = 2e5+5;
vector<ll> seg(4*mx);
vector<ll> lazy(4*mx,0);

int n,q;

void build( vector<ll>& nums, int l = 0, int r = n-1, int idx = 0){
	if(l == r){
		seg[idx] = nums[l];
		lazy[idx] = 0;
		return;
	}
	int m = (l+r)/2;
	int left = 2*idx+1;
	int right = 2*idx+2;
	build(nums, l,m,left);
	build(nums, m+1,r,right);
	seg[idx] = max(seg[left], seg[right]);
}

void prop(int l = 0, int r = n-1, int idx = 0){
	seg[idx] += (ll)(r-l+1)*lazy[idx];
	if(l != r){ // nao for folha
		int left = 2*idx+1;
		int right = 2*idx+2;
		lazy[left] += lazy[idx];
		lazy[right] += lazy[idx];
	}
	lazy[idx] = 0;
}

void update(int L, int R, ll val, int l = 0, int r = n-1, int idx = 0){
	if(R < l || L > r) return;
	prop(l,r,idx);
	if(L <= l && r <= R){
		lazy[idx] = val;
		prop(l,r,idx);
	}
	else{
		int m = (l+r)/2;
		int left = 2*idx+1;
		int right = 2*idx+2;
		update(L,R,val,l,m,left);
		update(L,R,val,m+1,r,right);
		seg[idx] = max(seg[left], seg[right]);
	}
}

ll query(int L, int R, int l = 0, int r = n-1, int idx = 0){
	prop(l,r,idx);
	if(R < l || L > r) return INT_MIN;
	if(L <= l && r <= R){
		return seg[idx];
	}
	int m = (l+r)/2;
	int left = 2*idx+1;
	int right = 2*idx+2;
	return max(query(L,R,l,m,left), query(L,R,m+1,r,right));
}

// lazy2 SegTree
vector<ll> seg2(4*mx);
vector<ll> lazy2(4*mx,0);


void build2( vector<ll>& nums, int l = 0, int r = n-1, int idx = 0){
	if(l == r){
		seg2[idx] = nums[l];
		lazy2[idx] = 0;
		return;
	}
	int m = (l+r)/2;
	int left = 2*idx+1;
	int right = 2*idx+2;
	build2(nums, l,m,left);
	build2(nums, m+1,r,right);
	seg2[idx] =  min(seg2[left],seg2[right]);
}

void prop2(int l = 0, int r = n-1, int idx = 0){
	seg2[idx] += (ll)(r-l+1)*lazy2[idx];
	if(l != r){ // nao for folha
		int left = 2*idx+1;
		int right = 2*idx+2;
		lazy2[left] += lazy2[idx];
		lazy2[right] += lazy2[idx];
	}
	lazy2[idx] = 0;
}

void update2(int L, int R, ll val, int l = 0, int r = n-1, int idx = 0){
	if(R < l || L > r) return;
	prop2(l,r,idx);
	if(L <= l && r <= R){
		lazy2[idx] = val;
		prop2(l,r,idx);
	}
	else{
		int m = (l+r)/2;
		int left = 2*idx+1;
		int right = 2*idx+2;
		update2(L,R,val,l,m,left);
		update2(L,R,val,m+1,r,right);
		seg2[idx] = min(seg2[left], seg2[right]);
	}
}

ll query2(int L, int R, int l = 0, int r = n-1, int idx = 0){
	prop2(l,r,idx);
	if(R < l || L > r) return INT_MAX;
	if(L <= l && r <= R){
		return seg2[idx];
	}
	int m = (l+r)/2;
	int left = 2*idx+1; 
	int right = 2*idx+2;
	return min(query2(L,R,l,m,left), query2(L,R,m+1,r,right));
}

int solve() {

    int d, k; cin >> n >> d >> k;

    vector<ll> arr(n, 0);

    build(arr);
    build2(arr);

    int l, r;

    for (int i = 0; i < k; i++) {
        cin >> l >> r; 
               l--; r--;

        update(l, r, 1);
        update2(l, r, 1);
    }

    ll mn = INT_MAX;
    ll mx = INT_MIN;
    ll mn_idx, mx_idx;

    ll a, b;
    for (int i = 0; i < n; i++) {
        a = query(i,i);
        b = query2(i,i);

        cout << a << '\n';

        if (a > mx) {
            mx = a;
            mx_idx = i+1;
        }

        if (b < mn) {
            mn = b;
            mn_idx = i+1;
        }
    }
    
    cout << '\n';

    cout << mx_idx << ' ' << mn_idx << '\n';
    

    cout << "\n\n\n\n";

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