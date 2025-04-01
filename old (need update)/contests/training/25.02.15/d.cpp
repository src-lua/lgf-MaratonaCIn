#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using pii = pair<int,int>;

template<typename T>
struct PT{
  T x, y;
  PT(T x=0, T y=0) : x(x),y(y){}
  bool operator < (PT o) const { return tie(x,y) < tie(o.x,o.y); }
  bool operator == (PT o) const { return tie(x,y) == tie(o.x,o.y); }
  PT operator + (PT o) const { return PT(x+o.x,y+o.y); }
  PT operator - (PT o) const { return PT(x-o.x,y-o.y); }
  PT operator * (T k) const { return PT(x*k,y*k); }
  PT operator / (T k) const { return PT(x/k,y/k); }
  T cross(PT o) const { return x*o.y - y*o.x; }
  T cross(PT a, PT b) const { return (a-*this).cross(b-*this); }
  T dot(PT o) const { return x*o.x + y*o.y; }
  T dist2() const { return x*x + y*y; }
  double len() const { return hypot(x,y); }
  PT perp() const { return PT(-y,x); }
  PT rotate(double a) const { return PT(x*cos(a)-y*sin(a), x*sin(a)+y*cos(a)); }
  int quad() { return (x<0)^3*(y<0); }
  bool ccw(PT<T> q, PT<T> r){ return (q-*this).cross(r-q) > 0;}
};

// retorna poligono no sentido anti horario, trocar pra < se quiser horario
template<typename T>
vector<PT<T>> convexHull(vector<PT<T>>& pts, bool sorted = false){
  if(!sorted) sort(begin(pts),end(pts));
  vector<PT<T>> h;
  h.reserve(pts.size() + 1);
  for(int it = 0; it < 2; it++){
    int start = h.size();
    for(PT<T>& c : pts){
      while((int)h.size() >= start + 2){
        PT<T> a = h[h.size()-2], b = h.back();
        // '>=' pra nao descartar pontos colineares
        if((b-a).cross(c-a) > 0) break; 
        h.pop_back();
      }
      h.push_back(c);
    }
    reverse(begin(pts),end(pts));
    h.pop_back();
  }
  if(h.size() == 2 && h[0] == h[1]) h.pop_back();
  return h;
}

double dist(PT<double> a, PT<double> b) {
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << fixed << setprecision(10);

    int n, l; cin >> n >> l;

    vector<PT<double>> points(n);

    double a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        points[i] = {a, b};
    }

    auto points2 = convexHull(points);

    vector<PT<double>> points3;
    int sz = points2.size();
    for (int i = 0; i < points2.size(); i++) {
        auto e = points2[i];

        if (e.x < points2[(i+1)%sz].x  && e.y < points2[(i-1+sz)%sz].y) {
            points3.push_back({e.x-l, e.y});
            points3.push_back({e.x, e.y-l});
        } else
        if (e.x > points2[(i-1+sz)%sz].x && e.y < points2[(i+1)%sz].y) {
            points3.push_back({e.x, e.y-l});
            points3.push_back({e.x+l, e.y});
        } else
        if (e.x > points2[(i+1)%sz].x && e.y > points2[(i-1+sz)%sz].y) {
            points3.push_back({e.x+l, e.y});
            points3.push_back({e.x, e.y+l});
        } else
        if (e.x < points2[(i-1+sz)%sz].x && e.y > points2[(i+1)%sz].y) {
            points3.push_back({e.x, e.y+l});
            points3.push_back({e.x-l, e.y});
        }
    }

    vector<PT<double>> points4 = convexHull(points3);

    double answ = 0;

    for (int i = 0; i < points4.size(); i++) {
        answ += dist(points4[i], points4[(i+1)%points4.size()]);
    }

    cout << answ;
    

    return 0;
}