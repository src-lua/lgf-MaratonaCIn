#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    int n; cin >> n;
    int m; cin >> m;
    vector<int> freq(m+1,0);
    vector<vector<int>> groups(n);

    int k;
    for (int i = 0; i < n; i++) {
        cin >> k;
    
        groups[i] = vector<int>(k);

        for (int j = 0; j < k; j++) {
            cin >> groups[i][j];
            freq[groups[i][j]]++;
        }
    }

    int answ = 0;
    int c;
    bool flag = true;
    while (flag){
        flag = false;
        for (auto e: groups) {
            c=0;
            for (auto i:e) {
                if (freq[i] == 1) c++;
            }
            if (c >= 2) {
                for (auto i:e) {
                    freq[i]--;
                }
                answ++;
                flag = true;
            }
        }
    }
    for (auto f: freq) {
        if (f) answ += 1;
    }
    
    cout << answ;
    
    return 0;
}