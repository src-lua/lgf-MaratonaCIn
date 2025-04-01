#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    int x, y;
    int sumx = 0, sumy = 0;
    
    if (n == 2) {
        int a ,b;
        cin >> x >> y;
        cin >> a >> b;
        
        if (x<a){   cout << x << ' ' << y;
        }  else     cout << a << ' ' << b;

        return 0;
    }

    for (int i = 0; i < n; i++) {
        cin >> x >> y;

        sumx += x; sumy +=y; 
    }

    sumx /= n; sumy /= n;

    cout << sumx << ' ' << sumy;
    

    return 0;
}