#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    string s;

    stack<string> pile;
    vector<string> hand;

    for (int i = 0; i < 52; i++) {
        cin >> s;
        if (i >= 52-25) hand.push_back(s);  
        else pile.push(s);
    }

    size_t y = 0;

    for (int i = 0; i < 3; i++) {
        int x = 0;
        if (pile.top()[0] >= '2' && pile.top()[0] <= '9') x = pile.top()[0] - '0';
        else x = 10;
        y += x;
        pile.pop();
        for (int j = 0; j < 10 - x; j++) pile.pop();
    }

    if (pile.size() >= y) {
        for (size_t i = 0; i < pile.size() - y; i++) {
            pile.pop();
        }
        cout << pile.top() << endl;
    }
    else {
        cout << hand[y - pile.size() - 1] << endl;
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c = 0; 
    int tc; cin >> tc; while (tc--) {
        cout << "Case " << ++c << ": "; 
        solve();
    }

    return 0;
}