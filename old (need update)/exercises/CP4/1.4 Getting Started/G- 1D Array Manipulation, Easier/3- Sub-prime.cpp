#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (1) {
        int banks, debentures;
        cin >> banks >> debentures;

        if (banks == 0 && debentures == 0) return 0;

        vector<int> reserves(banks + 1);

        int x;

        for (int i = 1; i <= banks; i++) {
            cin >> x;
            reserves[i] = x;
        }

        int a, b;

        for (int i = 0; i < debentures; i++) {
            cin >> a >> b >> x;

            reserves[a] -= x;
            reserves[b] += x;
        }

        bool answ = true;

        for (auto e : reserves) {
            if (e < 0) {
                answ = false;
                break;
            }
        }
        
        if (answ) cout << "S" << endl;
             else cout << "N" << endl;
    }
}