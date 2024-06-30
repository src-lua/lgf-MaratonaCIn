#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int index(int l) {
    int c = 2;
    while (1) {
        int curr = to_string(l).size();
        if (curr == l) return c;

        c++;
        l = curr;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s; 

    while (1) {
        cin >> s;

        if (s == "END") return 0;

        if (s.size() == 1 && s[0] == '1') {
            cout << 1 << endl;
            continue;
        }

        cout << index(s.size()) << endl;
    }

}