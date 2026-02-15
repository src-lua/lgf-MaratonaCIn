/**
 * Author:      Lua
 * Problem:     C - Check The Text
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/102263/problem/C
 * Status:      AC
 * Created:     14-02-2026 13:45:39
 **/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    string target;
    cin.ignore(); getline(cin, target);
    int q; cin >> q;

    string str = "";
    int offset = 0;
    for (int i = 0; i < q; i++) {
        string c; cin >> c;
        if (c == "CapsLock") offset = (offset ? 0 : 'A'-'a');
        else if (c == "Backspace") {if (!str.empty()) str.pop_back();}
        else if (c == "Space") str.push_back(' ');
        else str.push_back(c[0] + offset);
    }
    
    cout << (target == str ? "Correct" : "Incorrect") << '\n';

    return 0;
}
