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

        int l = 0;
        int k = 0;

        if (ppp[2] > pp[0]) {
            l++;
            if (ppp[1] > pp[0]) {
                k++;
                if (ppp[2] > pp[1] )l++;
            }
            else if (ppp[1] > pp[1]) l++;
        }

        else if (ppp[2] > pp[1]) {
            l++;
        }

        if (l==2) {
            cout << -1 << endl;
            continue;
        }

        int answ;

        if (l == 0) {
            answ = 1;
        }
        else { // if == 1
            answ = ppp[1] + 1;
        }

        if (k) {
            answ = ppp[2] + 1;
        }

        while((answ == ppp[2]) || (answ == ppp[1]) || (answ == ppp[0]) || (answ == pp[0]) || (answ == pp[1])) answ++;

        if (answ > 52) {
            cout << -1 << endl;
            continue;
        }

        cout << answ << endl;
    }
}