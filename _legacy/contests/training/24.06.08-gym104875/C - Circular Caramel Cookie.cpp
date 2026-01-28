#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(12);
    ll n;
    cin>>n;
    ll x;
    for(int i=n; i<=1e9;i++){
        x = sqrt(i);
        if(x*x == i){
            n = i;
            break;
        }
        x = sqrt(i+4);
        if(x*x - 4 == i){
            n = i;
            break;
        }
    }
    
    double resp = sqrt(sqrt(n+4)*sqrt(n+4) + (sqrt(n+4) - 2) * (sqrt(n+4) - 2));
    resp /= 2;
    cout<<resp<<"\n";
     
}