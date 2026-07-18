#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int n, k; cin >> n >> k;

    vector<char> s(n);
    priority_queue<char> lexico;

    cin.get();
    for (int i = 0; i < n; i++) {
        cin.get(s[i]);
        lexico.push(s[i]);
    }

    


    

    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

int tc; cin >> tc; while (tc--) {
    solve();
}

    return 0;
}