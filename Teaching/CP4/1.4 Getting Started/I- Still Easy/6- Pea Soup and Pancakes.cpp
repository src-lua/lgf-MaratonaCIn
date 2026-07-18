#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    string s;
    string name;
    bool pea_soup = false, pancakes  = false;

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        getline(cin >> ws, name);
        for (int j = 0; j < k; j++) {
            getline(cin >> ws, s);
            if (s == "pea soup") pea_soup = true;
            if (s == "pancakes") pancakes = true;
        }
        if (pea_soup && pancakes) {
            cout << name << endl;
            return 0;
        }
        else {
            pea_soup = false;
            pancakes = false;
        }
    }

    cout << "Anywhere is fine I guess" << endl;

    return 0;
}