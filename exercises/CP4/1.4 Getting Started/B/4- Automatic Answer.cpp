#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int n; cin >> n;
    cout << abs(((((((n*567/9) + 7492) * 235) /47)-498)/10)%10) << '\n';

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