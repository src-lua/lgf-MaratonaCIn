#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int n; cin >> n; n *= 2;

    for (int j = 0; j < n; j++)
    {
        if ((j/2) %2 == 0) {
            for (int i = 0; i < n; i+=2) {
                if ((i/2) % 2 == 0) cout << "##";
                else cout << "..";
            }
        }

        else {
            for (int i = 0; i < n; i+=2) {
                if ((i/2) % 2 == 1) cout << "##";
                else cout << "..";
            }

        }
        cout << endl;

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