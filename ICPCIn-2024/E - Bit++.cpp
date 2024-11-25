#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    string s;

    int answ = 0;

    for (int i = 0; i < n; i++) {
        cin >> s;


        for (auto e : s) {
            if (e == '+') {
                answ++;

                break;
            }

            if (e == '-') {
                answ--;

                break;
            }
        }
    }

    cout << answ << endl;

    return 0;
}