#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("i.in", "r", stdin);
    // freopen("output.txt", "w", stdout);

    string s; cin >> s;

    ll answ = 0;
    ll sz = s.size();

    // Não vai até o final pq se for 1 segmento só tem uma opção de letra inicial
    for (int i = 1; i < sz; i++) {
        if (sz % i == 0) // se for divisivel
            if (s.substr(0, i) == s.substr(sz-i,i)) // se o começo igual o final
                answ += sz; // adiciona os sz/i segmentos * i possibilidade de letra inicial 
                            // i * sz / i == sz
    }
    
    cout << answ+1 << endl;

    return 0;
}