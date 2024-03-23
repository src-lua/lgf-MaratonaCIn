#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll area; cin >> area;

    int pools; cin >> pools;

    int x;

    int target = -1;
    vector<int> vals(2);

    for (int i = 0; i < pools; i++) {
        cin >> x;
        
        if (target == -1) {
            if (area%x == 0) {
                target = area/x;
                vals[0] = x;
            }
        }
    
        else {
            if (x == target) {
                vals[1] = x;
                break;
            }
        }
    
    }
    
    sort(vals.begin(),vals.end());

    cout << vals[0] << ' ' << vals[1];
    

    return 0;
}