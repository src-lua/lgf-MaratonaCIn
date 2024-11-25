#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using pii = pair<int,int>;
using ll = long long;

// Time Complexity: O(log(n))
int lower(int l, int r, vector<pii>& arr, int target) { 
    int answ = -1;
    while (l <= r) {
        int m = l + (r - l) / 2;
 
        // If NOT SOLVE, ignore left half
        if (! (arr[m].first >= target) )
            l = m + 1;
 
        // If SOLVE, ignore right half
        else {
            r = m - 1;
            answ = m;
        }
    }
 
    if (answ == -1) answ = r;
    return answ;
}

int upper(int l, int r, vector<pii>& arr, int target) { 
    int answ = -1;
    while (l <= r) {
        int m = l + (r - l) / 2;
 
        // If NOT SOLVE, ignore left half
        if (! (arr[m].first > target) )
            l = m + 1;
 
        // If SOLVE, ignore right half
        else {
            r = m - 1;
            answ = m;
        }
    }
    if (answ == -1) answ = r;

    return answ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    

    vector<int> cords(n);
    vector<pii> cities(n);
    vector<ll> prefix; prefix.push_back(0);

    for (int i = 0; i < n; i++) {
        cin >> cords[i];
    }

    int x;

    for (int i = 0; i < n; i++) {
        cin >> x;
        cities[i] = {cords[i], x};
    }

    sort(cities.begin(), cities.end());
    
    for (auto [_, x] : cities) prefix.push_back(prefix.back() + x);

    int q; cin >> q;

    int l, r;

    for (int i = 0; i < q; i++) {
        cin >> l >> r;

        int lpos = lower(0, cities.size(), cities, l);
        int rpos = upper(lpos, cities.size(), cities, r);
    
        cout << prefix[rpos] - prefix[lpos] << endl;
    }

    return 0;
}