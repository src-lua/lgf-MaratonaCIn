#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    reverse(s.begin(), s.end());

    bool begin = true;

    for (size_t i = 0; i < s.size(); i++) {
        if (begin && s[i] != '0') begin = !begin;
        
        if (s[i] == '5') s[i] = '2';
        else if (s[i] == '2') s[i] = '5';
        
        if (!begin) cout << s[i];
    }

    cout << endl;
    

    return 0;
}