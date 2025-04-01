#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    int x;

    while (1) {
        cin >> a >> b;

        if (!(a | b)) return 0;

        unordered_set<int> aa;
        unordered_set<int> bb;

        for (int i = 0; i < a; i++) {
            cin >> x;
            aa.insert(x);
        }

        for (int i = 0; i < b; i++) {
            cin >> x;
            bb.insert(x);
        }

        int tradeA = 0;
        int tradeB = 0;

        for (auto e : aa) {
            if (bb.count(e) == 0) {
                tradeA++;
            }
        }

        for (auto e : bb) {
            if (aa.count(e) == 0) {
                tradeB++;
            }
        }

        cout << min(tradeA, tradeB) << endl;
    }
}