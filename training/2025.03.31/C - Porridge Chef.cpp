/*
Lucas Guimarães Fernandes </lgf_cin>
MaratonaCIn @ CIn - UFPE

[Porridge Chef](https://codeforces.com/gym/105741/problem/C)
Rating: NOT DEFINED
Tags: Implementation; Range Update;

Date: 2025-03-29
Status: Accepted during contest
*/


#include <bits/stdc++.h>

#define endl '\n'

using namespace std;


struct BIT {
	unordered_map<int, int> bit;
	int N = 1e9+1000;

	BIT(){}

	void update(int pos, int val){
		for(; pos < N; pos += pos&(-pos))
			bit[pos] += val;
	}

	int query(int pos){
		int sum = 0;
		for(; pos > 0; pos -= pos&(-pos))
			sum += bit[pos];
		return sum;
	}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    BIT bit;

    int n, q; cin >> n >> q;

    int l, r;
    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        bit.update(l, 1);
        bit.update(r+1, -1);
    }

    for (int i = 0; i < q; i++) {
        cin >> l;
        cout << bit.query(l) << '\n';
    }

    return 0;
}