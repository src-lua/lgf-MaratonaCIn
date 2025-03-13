#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

const int INF = INT_MAX;
const int max_size = 2e5 + 5;

vector<ll> seg(4 * max_size);
vector<ll> arr(max_size);

int n, q;
map<int,int> target;
ll operation(ll a, ll b) { return min(a,b); }

// Time complexity: O(n)                 // build()       
void build(int l = 0, int r = n - 1, int index = 0) {
    if (l == r) {
        seg[index] = arr[l];
        target[seg[index]]++;
        return;
    }
    int mid = l + (r - l) / 2;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    build(l, mid, left);
    build(mid + 1, r, right);
    seg[index] = operation(seg[left], seg[right]);
    target[seg[index]]++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int j; cin >> j;
    n = (j + 1)/2;

    int x;
    map<int, int> m;
    for (int i = 0; i < j; i++) {
        cin >> x;
        m[x]++;
    }

    if (m.size() != n) {
        cout << -1 << endl;
        return 0;
    }

    int i = 0;
    for (auto [k, v] : m) arr[i++] = k;
    build();

    for (auto [k, v] : m) {
        if (target[k] < m[k]) {
        cout << -1 << endl;
            return 0;
        }
    }
    
    for (auto [k, v] : m) {
        cout << k << ' ';
    } cout << endl;

    return 0;
}