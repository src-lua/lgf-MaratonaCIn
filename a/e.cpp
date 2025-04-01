#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

set<string> answ;

string swapx(const string& s) {
    string t = s;
    t[0] = s[1];
    t[1] = s[2];
    t[2] = s[3];
    t[3] = s[0];
    return t;
}

string swapy(const string& s) {
    string t = s;
    t[0] = s[5];
    t[5] = s[2];
    t[2] = s[4];
    t[4] = s[0];
    return t;
}

string swapz(const string& s) {
    string t = s;
    t[4] = s[1];
    t[1] = s[5];
    t[5] = s[3];
    t[3] = s[4];
    return t;
}

void solve(int r, int o, int y, int g, int b, int v, string s) {
    if (r > 0) solve(r-1, o, y, g, b, v, s+'R');
    if (o > 0) solve(r, o-1, y, g, b, v, s+'O');
    if (y > 0) solve(r, o, y-1, g, b, v, s+'Y');
    if (g > 0) solve(r, o, y, g-1, b, v, s+'G');
    if (b > 0) solve(r, o, y, g, b-1, v, s+'B');
    if (v > 0) solve(r, o, y, g, b, v-1, s+'V');

    if (s.size() == 6) {
        for (int i = 0; i < 4; i++) {
            if (answ.count(swapx(s))) return;
            s = swapx(s);
            for (int i2 = 0; i2 < 4; i2++) {
                if (answ.count(swapy(s))) return;
                s = swapy(s);
                for (int i3 = 0; i3 < 4; i3++) {
                    if (answ.count(swapz(s))) return;
                    s = swapz(s);
                }
            }
        }

        answ.insert(s);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s;
    int r, o, y, g, b, v;
    r = o = y = g = b = v = 0;
    for (auto e : s) {
        if (e == 'R') r++;
        if (e == 'O') o++;
        if (e == 'Y') y++;
        if (e == 'G') g++;
        if (e == 'B') b++;
        if (e == 'V') v++;
    }

    solve(r, o, y, g, b, v, "");

    cout << answ.size() << endl;

    return 0;
}