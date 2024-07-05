#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s;

    for (auto i = s.begin(); i != s.end(); i++) {
        
         if((i+1 != s.end() && i+2 != s.end()) && (*i != *(i+1) && *i != *(i+2) && *(i+1) != *(i+2))) {
            cout << "C";
            i += 2;
        }
        else {
            switch (*i) {
                case 'R':
                    cout << "S";
                    break;
                case 'B':
                    cout << "K";
                    break;
                case 'L':
                    cout << "H";
                    break;
            }
        }
    }
    cout << endl;

    return 0;
}