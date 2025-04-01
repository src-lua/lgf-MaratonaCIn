#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {
    int n;

    multiset<int> s;

    cin >> n;
    multiset<int>::iterator median;

    // multiset::insert -> The relative ordering of equivalent elements is preserved, and newly inserted elements follow their equivalents already in the container.

    while(n != 0) {
        if (n != -1) {
            if (s.empty()) {
                s.insert(n);
                median = s.begin();
            } else {
                // - - M - -
                // - - M - - I
                // Insert de elemento maior em set impar;
                if (n >= *median && s.size() % 2 == 1) {
                    s.insert(n);
                }
                //   - - M - -
                // I - M - - -
                // Insert de elemento menor em set impar;
                else if (n < *median && s.size() % 2 == 1) {
                    s.insert(n);
                    median--;
                }
                // - M - -
                // - - M - I
                // Insert de elemento maior em set par;
                else if (n >= *median && s.size() % 2 == 0) {
                    s.insert(n);
                    median++;
                }
                //   - M - - 
                // I - M - - 
                // Insert de elemento menor em set par;
                else if (n < *median && s.size() % 2 == 0) {
                    s.insert(n);
                }
            }
        }
        else {
            cout << *median << '\n';
            auto aux = median;
            if (s.size() % 2 == 1) median--;
            else median++;
            s.erase(aux);
        }

        cin >> n;
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}