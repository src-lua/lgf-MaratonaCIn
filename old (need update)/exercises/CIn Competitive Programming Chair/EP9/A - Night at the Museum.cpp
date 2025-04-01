#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s;

    int answ = 0;

    s = 'a'+s;

    for (int idx = 1; idx < s.size(); idx++) {
        answ += min(
            ((s[idx]-s[idx-1]+26)%26), 
            ((s[idx-1]-s[idx]+26)%26) 
        );
    }

    cout << answ << endl;    

    return 0;
}