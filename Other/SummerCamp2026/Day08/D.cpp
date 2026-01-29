/**
 * Author:      Lua
 * Problem:     D
 * Link:        https://vjudge.net/contest/784977#problem/D
 * Status:      AC
 * Created:     28-01-2026 16:28:16
 **/

#include <bits/stdc++.h>
#define ll long long
#define ALL(x) x.begin(), x.end()
#define vi vector<int>
#define endl "\n"
using namespace std;


int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    int tt; cin >> tt;
    while(tt--){
        string s,t; cin >> s >> t;
        
        int n = s.size(), m = t.size();
    
        string fixo = s;

        for(int i=m-1; i>=0; i--){

            for(int j=n-1; j>=0; j--){
                if(fixo[j] == t[i]){
                    fixo[j] = '*';
                    break;
                }
            }

        }

        string ans = "";
        for(int i=0; i<n; i++){
            if(fixo[i] == '*') ans += s[i];
        }

        cout << (ans == t ? "YES" : "NO") << endl;
    }   

    
}