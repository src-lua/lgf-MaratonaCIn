#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    stack<string> pile;
    bool snowcoat = false;

    string instr, s;

    for (int i = 0; i < n; i++) {
        cin >> instr;

        if (instr == "put") {
            cin >> s;

            pile.push(s);

            if (s == "snowcoat") snowcoat = true;
        } else

        if (instr == "get") {
            if (pile.empty()) cout << "empty" << endl;

            else if (snowcoat) {
                cout << pile.top() << endl;
                if (pile.top() == "snowcoat") snowcoat = false;
                pile.pop();
            }
            else {
                while (!pile.empty() && pile.top() == "snowcoat") pile.pop();
                if (pile.empty()) cout << "empty" << endl;
                else {
                    cout << pile.top() << endl;
                    pile.pop();
                }
            }
        } else

        if (instr == "iditarod") {
            if (snowcoat) {
                snowcoat = false;
                cout << "winner winner chicken dinner :)" << endl;
            }
            else {
                cout << "oopsimcold :(" << endl;
            }
        }
    }
    

    return 0;
}