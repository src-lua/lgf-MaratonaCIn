#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<bool> songs(n+1, false);
    int resp = 0;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        int temp = 0;
        for(int j=0;j<m;j++){
            int a;
            cin>>a;
            if(songs[a] == false){
                songs[a] = true;
                temp++;
            }
        }
        resp = max(temp, resp);
    }
    cout<<resp<<"\n";
}