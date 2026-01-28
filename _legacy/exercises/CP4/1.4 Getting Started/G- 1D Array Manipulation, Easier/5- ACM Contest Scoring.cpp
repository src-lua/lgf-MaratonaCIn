#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    char letter;
    string judge;

    map<char, int> penalty;
    vector<bool> solved(26, false);

    int c = 0;
    int p = 0;

    while (1) {
        cin >> n;

        if (n == -1) break;

        cin >> letter >> judge;

        if (judge == "wrong") {
            penalty[letter] += 20;
        } else {
            penalty[letter] += n;
            solved[letter - 'A'] = true;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (solved[i]) {
            c++;
            p += penalty['A' + i];
        }
    }

    cout << c << " " << p << endl;

    return 0;
}