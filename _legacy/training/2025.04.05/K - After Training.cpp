#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    
    vector<int> seq;

    int mid = (m+1)/2;
    seq.push_back(mid);

    if (m%2 == 0) {
        for (int i = 1; i < mid; i++) {
            seq.push_back(mid+i);
            seq.push_back(mid-i);
        }
        seq.push_back(m);
    }
    else {
        for (int i = 1; i < mid; i++) {
            seq.push_back(mid-i);
            seq.push_back(mid+i);
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << seq[i%m] << '\n';
    }

    return 0;
}