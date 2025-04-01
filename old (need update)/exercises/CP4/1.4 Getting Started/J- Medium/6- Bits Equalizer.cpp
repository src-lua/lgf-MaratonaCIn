#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    string s, t;
    cin >> s >> t;

    int n = s.size();
    int answ = 0;

    int diffOne = 0;
    int diffZero = 0;
    int marksOnZero = 0;
    int markOnOne = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            if (s[i] == '0') diffZero++;
            else if (s[i] == '1') diffOne++;
            else if (s[i] == '?' && t[i] == '1') marksOnZero++;
            else if (s[i] == '?' && t[i] == '0') markOnOne++;
        }
    }

    int d;

    answ =+ min(diffOne, diffZero);
    d = min(diffOne, diffZero);
    diffOne -= d;
    diffZero -= d;

    answ += min(diffOne, marksOnZero)*2;
    d = min(diffOne, marksOnZero);
    diffOne -= d;
    marksOnZero -= d;

    answ += min(diffZero, diffOne);
    d = min(diffZero, diffOne);
    diffZero -= d; 
    diffOne -= d;

    answ += diffZero + marksOnZero + markOnOne;
    if (diffOne) answ = -1;

    cout << answ << endl;


    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c = 0;
    int tc; cin >> tc; while (tc--) {
        cout << "Case " << ++ c << ": "; 
        solve();
    }

    return 0;
}