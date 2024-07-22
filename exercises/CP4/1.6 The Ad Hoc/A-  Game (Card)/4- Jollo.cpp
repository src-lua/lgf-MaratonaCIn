#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> ppp(3);
    vector<int> pp(2);

    while (1) {
        cin >> ppp[0] >> ppp[1] >> ppp[2];
        cin >> pp[0] >> pp[1];

        if (!(ppp[0]|ppp[1]|ppp[2]|pp[0]|pp[1])) return 0;

        sort(ppp.begin(), ppp.end());
        sort(pp.begin(), pp.end());

        if ((ppp[2] > pp[1]) && (ppp[1] > pp[0])) {
            cout << -1 << endl;
            continue;
        } 

        int answ = ppp[1]+1;

        while((answ == ppp[2]) || (answ == pp[0]) || (answ == pp[1])) answ++;

        cout << answ << endl;
    }
}