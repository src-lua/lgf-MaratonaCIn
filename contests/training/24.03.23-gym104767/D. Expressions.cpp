#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;

    vector<bool> group;
    vector<pii> group_index;
    group.push_back(true);
    group_index.push_back({1,-1});
    
    int index = 0;

    int x; char c;
    for (int i = 0; i < n-1; i++) {
        cin >> x;

        if (x %2 == 1) group[index] = !group[index];

        cin >> c;

        if (c != '*') {
            group_index[index] = {group_index.back().first, i+1};
            group_index.push_back({i+2, -1});
            group.push_back(true);
            index++;
        }
    }
    cin >> x;
    if (x %2 == 1) group[index] = !group[index];

    int odd = 0;

    for(auto e: group) {
        if (!e) odd++;
    }

    if (odd%2==0) cout << "even";
    else cout << "odd";

    int y;
    for (int i = 0; i < q; i++) {
        cin >> x >> y;

        for (int i = 0; i < group_index.size(); i++) {
            if (group_index[i].first < x && x < group_index[i].second) {
                if ((group[i] && y%2!=0) || (!group[i] && y%2==0)) {
                    group[i] = !group[i];
                }
                
                break;
            }
        }
            
    }
    

    return 0;
}