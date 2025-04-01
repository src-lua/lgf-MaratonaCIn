#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s;

    string stk; // using string as stack<char>

    for (auto e : s) {
        stk += e; // push to stack

        if (stk.size() >= 3 && stk.substr(stk.size()-3) == "ABC") 
            stk.erase(stk.end()-3, stk.end()); // pop from stack
    }

    cout << stk;

    return 0;
}