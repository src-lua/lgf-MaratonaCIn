#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;

    cin >> s;

    s = to_string(stoi(s) + 1);

    while (!(s[0] != s[1] && s[0] != s[2] && s[0] != s[3] &&
             s[1] != s[2] && s[1] != s[3] && s[2] != s[3])) {

        s = to_string(stoi(s) + 1);

    }

    cout << s << endl;

    return 0;
}