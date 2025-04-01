#include <bits/stdc++.h>

#define endl '\n'

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long a, b, k, l,w,h;
    cin >> a >> b >>k;
    cin >> l >> w >> h;

    long long  qtd1 = (a/l) * (b/w) * (k/h); 
    long long  qtd2 = (a/l) * (b/h) * (k/w);
    long long  qtd3 = (a/h) * (b/l) * (k/w);
    long long  qtd4 = (a/h) * (b/w) * (k/l);
    long long  qtd5 = (a/w) * (b/h) * (k/l);
    long long  qtd6 = (a/w) * (b/l) * (k/h);

    long long qtd = max ({qtd1,qtd2,qtd3,qtd4,qtd5,qtd6});
    cout << qtd;
    return 0;
}