/**
 * Author:      Lua
 * Problem:     C
 * Link:        https://vjudge.net/contest/782311#problem/C
 * Status:      AC
 * Created:     29-01-2026 11:15:23
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin>>n>>k;
    vector<int> moves(k);
    for(int i=0;i<k;i++)cin>>moves[i];
    sort(moves.begin(), moves.end());
    int dp[n+1];
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        dp[i] = 0;
        for(int j=0;j<k;j++){
            if(i - moves[j] < 0)break;
            if(dp[i-moves[j]] == 0){
                dp[i] = 1;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++)cout<<(dp[i]?"W":"L");
    return 0;
}
