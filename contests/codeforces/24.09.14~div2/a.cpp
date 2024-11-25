#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

const string base = "aeiou";

int s() {
    
}

int solve() {

    map<char,int> reps;
    
    reps['a'] = 1;
    reps['e'] = 1;
    reps['i'] = 1;
    reps['o'] = 1;
    reps['u'] = 1;

    int n; cin >> n;

    int curr = 5;

    if (n <= 5) cout << base.substr(0, n) << endl;
    else {
        while (curr < n) {



        }
    }


    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}