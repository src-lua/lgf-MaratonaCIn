#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int n; cin >> n;
    string s; cin >> s;
    map<char,int> freq;
    for (auto e : s) freq[e]++;

    if (freq['L'] == freq['I'] && freq['I'] == freq['T']) {
        cout << 0 << endl;
        return 0;
    }

    int mx = max({freq['L'], freq['I'], freq['T']});

    map<char, int> need;
    need['L'] = mx - freq['L']; 
    need['I'] = mx - freq['I']; 
    need['T'] = mx - freq['T']; 

    vector<int> answ;

    for (int i = 0; i < 2*n; i++) s = (s[0]) + s;
    
    int i = 2*n;
    int offset = -2*n+1; 
    while(i < s.size()-1 && answ.size() <= n*2) {
        if ((s[i] == 'L' && s[i+1] == 'I' || s[i] == 'I' && s[i+1] == 'L') && need['T']) {
            answ.push_back(i+offset);
            offset+=1;
            s[i-1] = s[i];
            s[i] = 'T';
            need['T']--;
            i-=2;
        } else
        if ((s[i] == 'L' && s[i+1] == 'T' || s[i] == 'T' && s[i+1] == 'L') && need['I']) {
            answ.push_back(i+offset);
            offset+=1;
            s[i-1] = s[i];
            s[i] = 'I';
            need['I']--;
            i-=2;
        } else
        if ((s[i] == 'I' && s[i+1] == 'T' || s[i] == 'T' && s[i+1] == 'I') && need['L']) {
            answ.push_back(i+offset);
            offset+=1;
            s[i-1] = s[i];
            s[i] = 'L';
            need['L']--;
            i-=2;
        }
        i++;

        if (i == s.size()-2) {
            i = 2*n-answ.size();
            offset = -(2*n-answ.size())+1;
            need['L']++; need['T']++; need['I']++;
        }
        if (need['L'] == 0 && need['T'] == 0 && need['I'] == 0) break;
    }
    
    if (need['L'] == 0 && need['T'] == 0 && need['I'] == 0) {
        cout << answ.size() << endl;
        for (auto e : answ) cout << e << endl;
    } else {
        cout << -1 << endl;
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