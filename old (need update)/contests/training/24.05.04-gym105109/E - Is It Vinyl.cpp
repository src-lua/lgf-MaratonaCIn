#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<double> xs(10);
    vector<double> ys(10);
    for(int i=0;i<10;i++){
        cin>>xs[i];
        cin>>ys[i];
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    int best_x = 0;
    int best_y = 0;
    int x_igual = 1;
    int y_igual = 1;
    double mx = 2*(1e-6);
    for(int i=0;i<9;i++){
        if(abs(xs[i+1] - xs[i]) <= mx)x_igual++;
        else {
            best_x = max(best_x, x_igual);
            x_igual = 1;
        }
        if(abs(ys[i+1] - ys[i]) <= mx)y_igual++;
        else{ 
            best_y = max(best_y, y_igual);
            y_igual = 1;
        }
    }
    if(best_x>=3 || best_y >=3 || x_igual >= 3|| y_igual >= 3)cout<<"CASSETTE\n";
    else cout<<"VINYL\n";

}