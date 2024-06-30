#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int c = 0;

    while (1) {
        cin >> n;
        if (!n) return 0;

        int x;
        int answ = 0;

        for (int i = 0; i < n; i++) {
            cin >> x;
            if (x) answ++;
            else answ--;
        }

        cout << "Case "<< ++c << ": " << answ << '\n';
    }
}