/**
 * Author:      Lua
 * Problem:     O
 * Link:        https://vjudge.net/contest/783478#problem/O
 * Status:      AC
 * Created:     29-01-2026 11:21:13
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
    int l, g;
    cin>>l>>g;
    while(l != 0 and g != 0){
        vector<pair<int, int>> pos(g);
        for(int i=0;i<g;i++){
            int x, rg;
            cin>>x>>rg;
            pos[i] = {max(x-rg,0),min(x + rg, l)};
        } 
        sort(pos.begin(), pos.end());
        if(pos[0].first > 0){
            cout << -1 << endl;
            cin >> l >> g;
            continue;
        }

        pair<int, int> curr = pos[0];
        int lstpos = -1, ans = 0;
        for(int i=1;i<g;i++){
            auto [st, fm] = pos[i];
            if(st > lstpos and st > curr.second){
                ans = -1;
                break;
            }
            if(st == curr.first){
                curr = pos[i];
                continue;
            }
            if(st >= curr.first and fm <= curr.second)continue;
            if(st <= lstpos and fm > curr.second){
                curr = pos[i];
                continue;
            }
            if(st >= curr.first and fm > curr.second){
                lstpos = curr.second + 1;
                curr = pos[i];
                ans++;
                continue;
            }
        }

        if(curr.second < l){
            cout << -1 << endl;
            cin >> l >> g;
            continue;
        }

        if(ans != -1){
            ans++;
            cout<<(g - ans)<<"\n";
        }
        else cout<<"-1\n";
        cin>>l>>g;
    }

}