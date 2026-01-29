/**
 * Author:      Lua
 * Problem:     F
 * Link:        https://vjudge.net/contest/783478#problem/F
 * Status:      AC
 * Created:     29-01-2026 11:21:13
 **/

#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const int inf = 1e9;
void solve() {
	string s;
    cin>>s;
    vector<int> freq(28, 0);
    for(char a:s){
        freq[a - 'A']++;
    }
    int qtip = 0;
    for(int i=0;i<28;i++)
        if(freq[i] & 1)
            qtip++;
    if(qtip > 1)cout<<"NO SOLUTION\n";
    else {
        string resp = "";
        string meio = "";
        for(int i=0;i<28;i++){
            if(freq[i] & 1){
                for(int j=0;j<freq[i];j++){
                    meio += ('A' + i);
                }
                continue;
            }    
            for(int j=0;j<(freq[i]/2);j++){
                resp += ('A' + i);
            }
        }
        string trocado = resp;
        reverse(trocado.begin(), trocado.end());
        cout<<resp + meio + trocado<<"\n";
    }

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
	// freopen("in.txt", "r", stdin);
	solve();
    return 0;
}
