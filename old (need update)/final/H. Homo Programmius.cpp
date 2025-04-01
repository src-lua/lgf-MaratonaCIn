#include <bits/stdc++.h>

// #define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    string s; cin >> s;
    set<int> pos;

    pos.insert(-1), pos.insert(s.size());

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            pos.insert(i);
        }
    }

    long long int answ = ((s.size()+1)*s.size())/2;

    for (auto i = ++pos.begin(); i != pos.end(); i++) {

        auto prev = --i;
        ++i;
        
        int sz = *i-*prev-1;
        
        answ -= ((sz+1)*sz)/2;
    }
    
    int m; cin >> m;
    int p, v;
    for (int _ = 0; _ < m; _++) {
        cin >> p >> v; p--;
                
        if (v == 0) {
            auto i = pos.lower_bound(p);
            auto prev = --i;
            ++i;
            auto next = ++i;
            --i;
            int prevsz1 = *i-*prev-1;
            int prevsz2 = *next-*i-1;
            if (next == pos.end()) prevsz2 = 0;
            
            pos.erase(p);
            i = pos.lower_bound(p);
            prev = --i;
            ++i;
            
            int sz = *i-*prev-1;
            
            answ += ((prevsz1+1)*prevsz1)/2;
            answ += ((prevsz2+1)*prevsz2)/2;
            answ -= ((sz+1)*sz)/2;
        }
        else {
            auto i = pos.lower_bound(p);
            auto prev = --i;
            ++i;
            int prevsz = *i-*prev-1;
            
            pos.insert(p);
            i = pos.lower_bound(p);
            prev = --i;
            ++i;
            auto next = ++i;
            --i;
            
            int sz1 = *i-*prev-1;
            int sz2 = *next-*i-1;
            if (next == pos.end()) sz2 = 0;
            
            answ += ((prevsz+1)*prevsz)/2;
            answ -= ((sz1+1)*sz1)/2;
            answ -= ((sz2+1)*sz2)/2;
        }

        cout << answ << endl;
    }

    return 0;
}