#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s, t;
    cin >> s >> t;

    vector<int> connection;
    vector<int> top;
    vector<int> bot;
    vector<int> empty;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '#' && t[i] == '#') connection.push_back(i);
        else if (s[i] == '#') top.push_back(i);
        else if (t[i] == '#') bot.push_back(i);
        else empty.push_back(i);
    }
    
    if (top.size() && bot.size() && !connection.size()) cout << "NO\n";
    else {
        cout << "YES\n";
        for (auto e : top) cout << s[e];
        for (auto e : connection) cout << s[e];
        for (auto e : bot) cout << s[e];
        for (auto e : empty) cout << s[e];
        cout << endl;

        for (auto e : top) cout << t[e];
        for (auto e : connection) cout << t[e];
        for (auto e : bot) cout << t[e];
        for (auto e : empty) cout << t[e];
        cout << endl;
    }

    return 0;
}