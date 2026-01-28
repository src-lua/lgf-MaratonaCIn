#include <bits/stdc++.h>
using namespace std;
#define ll long long int
double dist(pair<double, double> pa, pair<double, double> pb){
    return sqrt((pa.first - pb.first)*(pa.first - pb.first) + (pa.second - pb.second)*(pa.second - pb.second));
}
int  main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    double r;
    cin>>r;
    vector<pair<double, double>> points(3);
    int x=0, y=0;
    for(int i=0;i<3;i++){
        cin>>x>>y;
        points[i] = {x, y};
    }
    double cx=0, cy=0;
    cx = points[0].first + points[1].first + points[2].first;
    cx /= 3;
    cy = points[0].second + points[1].second + points[2].second;
    cy /= 3;
    vector<double> dis(3);
    for(int i=0;i<3;i++){
        dis[i] = dist({cx, cy}, points[i]);
    }
    double qt = 1e-3;
    for(int i=0;i<3;i++){
        if(dis[i] > r + (5*qt)){
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
    cout<<cx<<" "<<cy;

}