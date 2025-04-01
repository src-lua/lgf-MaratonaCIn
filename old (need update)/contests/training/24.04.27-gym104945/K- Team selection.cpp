#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int max_size = 2e5+5;
vector<ll> arr(max_size+1,0);
vector<ll> bit(max_size+1,0);
int n, q;

ll query(int i){ // [1,i]
	ll ret = 0;
	for(; i > 0; i -= i & -i) {
		ret += bit[i];
	}
	return ret;
}

ll queryRange(int l, int r){    // [l,r]
	ll qr = query(r);
	ll ql = query(l-1);
	return qr-ql;
}
void increment(ll index, ll value){     
	for(; index <= n; index += index & -index) {
		bit[index] += value;
	}
}
void build(const vector<ll>& nums){
	for(int i = 0; i < nums.size(); i++){
		increment(i+1,nums[i]);
	}
}


int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    int n; cin >> n;

    vector<ll> nums(n,0);
    build(nums);

    vector<int> arr1(n/2);
    vector<int> arr2(n/2);
    vector<bool> pick(n, false);

    for (int i = 0; i < n/2; i++) {
        cin >> arr1[i];
    }
    for (int i = 0; i < n/2; i++) {
        cin >> arr2[i];
    }

    int c, idx;
    int x;

    for (int i = 0; i < n/2; i++) {
        arr1[i] = arr1[i]+queryRange(n-arr1[i],n-arr1[i]);
        increment(n-arr1[i]-1, 1);

        arr2[i] = arr2[i]+queryRange(n-arr2[i],n-arr2[i]);
        increment(n-arr2[i]-1, 1);
    }

    for (auto e: arr1) {
        cout << e << ' ';
    } cout << '\n';
    for (auto e: arr2) {
        cout << e << ' ';
    } cout << '\n';
    
}