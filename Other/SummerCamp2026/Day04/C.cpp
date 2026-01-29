/**
 * Author:      Lua
 * Problem:     C
 * Link:        https://vjudge.net/contest/783478#problem/C
 * Status:      AC
 * Created:     29-01-2026 11:21:13
 **/

#include <iostream>
#include <vector>

#define vi vector<int>

using namespace std;

void solve() {
    int n;
    cin>>n;
    int ans = 0, cnt = 0, x = 0;
    for(int i=0;i<n;i++){
        cin>>x;
        if(x == 1)cnt++;
        ans ^= x;
    }
    if(cnt == n){
        cout<<(cnt%2 == 0?"John":"Brother")<<"\n";
    }
    else cout<<(ans == 0?"Brother":"John")<<"\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
	// freopen("in.txt", "r", stdin);
    int t; cin >> t;
    while(t--){

        solve();
    }
    return 0;
}
