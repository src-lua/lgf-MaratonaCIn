#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int s, l; cin >> s >> l;

    if (n%2 == 1) cout << "Samuel\n";
    else cout << "Lleumas\n";

    if (n == 1) cout << s << endl;
    else cout << (n-1)/2 * s + (n)/2 * l << endl;

    return 0;
}