#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;

    vector<bool> families(n, false);

    int a; 
    char b;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;

        if (b == 'M' && !families[a]) {
            families[a] = true;
            cout << "Yes" << endl;
        }
        else cout << "No" << endl; 
    }
    

    return 0;
}