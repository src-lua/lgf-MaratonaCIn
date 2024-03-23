#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;

    vector<int> numbers(n);
    vector<int> group;
    // vector<pii> group_index;
    vector<int> group_index;
    group.push_back(0);
    // group_index.push_back({1,-1});
    group_index.push_back(0);

    int index = 0;

    char c;
    for (int i = 0; i < n-1; i++) {
        cin >> numbers[i];

        if (numbers[i] %2 == 0) group[index]++;

        cin >> c;

        if (c != '*') {
            // group_index[index] = {group_index.back().first, i+1};
            // group_index.push_back({i+2, -1});
            group_index.push_back(i+1);
            group.push_back(0);
            index++;
        }
    }
    cin >> numbers[n-1];
    if (numbers[n-1] %2 == 0) group[index]++;
    group_index.push_back(n);

    int odd = 0;

    for(auto e: group) {
        if (e == 0) odd++;
    }

    if (odd%2==0) cout << "even" << endl;
    else cout << "odd" << endl;

    int x, y;
    for (int j = 0; j < q; j++) {
        cin >> x >> y;
        if (numbers[x-1]%2 != y%2) {
            numbers[x-1] = y;
            // for (int i = 0; i < int(group_index.size()); i++) {
                // if (group_index[i].first <= x && x <= group_index[i].second) {
                        // if (y%2==0) group[i]++; else group[i]--;
                        // break;
                    // }
            // }
            int i = lower_bound(group_index.begin(), group_index.end(), x) - group_index.begin()-1;
            if (y%2==0) group[i]++; else group[i]--;
        }

        odd = 0; 
        for(auto e: group) {
            if (e == 0) odd++;
        }

        if (odd%2==0) cout << "even" << endl;
        else cout << "odd" << endl;
            
    }
    

    return 0;
    }