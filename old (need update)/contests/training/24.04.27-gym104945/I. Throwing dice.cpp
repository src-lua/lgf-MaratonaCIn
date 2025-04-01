#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
    int x,y;
    cin >> x>>y;
    int sum1=0,sum2=0;
    int e;
    for(int i =0;i<x;i++)
    {
        cin>>e;
        sum1+=e;
    }
    for(int i =0;i<y;i++)
    {
        cin >> e;
        sum2+=e;
    }
    int ans = 0;
    ans += x-y;
    ans += sum1-sum2;
    if(ans>0) cout<<"ALICE\n";
    else if(ans<0) cout<<"BOB\n";
    else cout <<"TIED\n";
}