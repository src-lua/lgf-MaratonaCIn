#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int  main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<pair<int, int>> iris(n);
    vector<ll> demon(n);
    int num = 0;
    for(int i=0;i<n;i++){
        cin>>num;
        iris[i] = {num, i};
    }
    for(int i=0;i<n;i++)cin>>demon[i];
    sort(iris.begin(), iris.end());
    vector<ll> prefx(n);
    prefx[0]  = demon[iris[0].second];
    for(int i=1;i<n;i++){
        prefx[i] = prefx[i-1] + demon[iris[i].second];
    } 
    bool iriswin = false;
    for(int i=0;i<n;i++){
        if(prefx[i] >= iris[i].first){
            iriswin = true;
            break;
        }
    }
    if(iriswin){
        cout<<"Redemption\n";
    }
    else cout<<"Dire victory\n";
}