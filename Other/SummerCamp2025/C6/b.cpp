#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s, t;
    cin >> s >> t;

    int answ = 0;

    for (int i = 0; i < int(s.size())-int(t.size())+1; i++) {
        bool flag = true;
        for (int j = 0; j < t.size(); j++) {
            if (s[i+j] == t[j]) {
                flag = false;
                break;
            }
        }
        if(flag) answ++;
    }

    cout << answ << endl;    

    return 0;
}