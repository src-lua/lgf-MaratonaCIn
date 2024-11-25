#include <bits/stdc++.h>

#pragma GCC optimize("O3,unroll-loops")
#define endl '\n'

using namespace std;
using ll = long long;

const int INF = INT_MAX;
const int max_size = 2e5 + 5;
vector<ll> seg(4 * max_size);
vector<ll> arr(max_size);

int n, q;

ll operation(ll a, ll b) { return max(a, b); }

// Time complexity: O(n)                 // build()       
void build(int l = 0, int r = n - 1, int index = 0) {
    if (l == r) {
        seg[index] = arr[l];
        return;
    }
    int mid = l + (r - l) / 2;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    build(l, mid, left);
    build(mid + 1, r, right);
    seg[index] = operation(seg[left], seg[right]);
}

// Time complexity: O(log(n))                // query(L-1, R-1)
ll query(int L, int R, int l = 0, int r = n - 1, int index = 0) {
    if (R < l || L > r) return INT_MIN;  // Neutral element of the operation
    if (L <= l && r <= R) return seg[index];

    int mid = l + (r - l) / 2;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    ll ql = query(L, R, l, mid, left);
    ll qr = query(L, R, mid + 1, r, right);
    return operation(ql, qr);
}

string dir;

int go(int pos) {

    while ((dir[pos] == 'R') || (pos+1 < n && dir[pos+1] == 'L')) pos++;

    return pos;
}

int solve() {

    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    build();

    cin >> dir;

    int x;
    int possible;
    bool impossible;

    for (int j = 0; j < q; j++) {
        cin >> x; x--;

        if (dir[x] == 'R') dir[x] = 'L'; else dir[x] = 'R';
        
        impossible = false;
        
        int i = 0;
        while(i < n) {
            possible = go(i);
            
            if (query(i, possible)-1 > possible) {
                cout << "NO\n";
                impossible = true;
                break;
            }

            i = possible+1;
        }
        
        if (!impossible) {
            cout << "YES\n";
        }
    }
    

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