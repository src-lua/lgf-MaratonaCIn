#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    map<int, int> freq;
    int x;

    for (int i = 0; i < n; i++){
        cin >> x;
        freq[x]++;
    }

    int maxv = 0;

    for(auto [k, v] : freq) {
        maxv = max(maxv, v);
    }

    cout << maxv << endl;
    
    return 0;
}