#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s;

    map<char, int> last;
    map<char, int> size;
    map<char, bool> can;

    for (int i = 0; i < s.size(); i++) {
        auto e = s[i];


        if (last.count(e) == 0) {
            last[e] = i;
            size[e] = i+1;
        } else can[e] = true;
        size[e] = max(size[e], i-last[e]);
        last[e] = i;
    }

    int answ = s.size()/2 + 1;

    for (auto [k,v] : size) {
        if (can[k]) answ = min(answ, max(v, int(s.size())-last[k]));
    }
    cout << answ << endl;
 
    return 0;
}