/**
 * Author:      Lua
 * Problem:     P
 * Link:        https://vjudge.net/contest/783478#problem/P
 * Status:      AC
 * Created:     29-01-2026 11:21:13
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll,ll>;

struct PT {
	ll x, y;
	PT(ll x=0, ll y=0) : x(x), y(y) {}

	PT operator+(const PT&a)const{return PT(x+a.x, y+a.y);}
	PT operator-(const PT&a)const{return PT(x-a.x, y-a.y);}
	ll operator*(const PT&a)const{return  (x*a.x + y*a.y);} //DOT
	ll operator%(const PT&a)const{return  (x*a.y - y*a.x);} //Cross
	PT operator*(ll c) const{ return PT(x*c, y*c); }
	PT operator/(ll c) const{ return PT(x/c, y/c); }
	bool operator==(const PT&a) const{ return x == a.x && y == a.y; }
	bool operator< (const PT&a) const{ return tie(x, y) < tie(a.x, a.y); }
	
	ll cross(const PT&a, const PT&b) const{ return (a-*this) % (b-*this); } // (a-p) % (b-p)
	int quad() { return (x<0)^3*(y<0); } //cartesian plane quadrant |0++|1-+|2--|3+-|
	bool ccw(PT q, PT r){ return (q-*this) % (r-q) > 0;}
};

vector<PT> ConvexHull(vector<PT>& pts, bool sorted=false){
	if(!sorted) sort(begin(pts), end(pts));
	pts.resize(unique(begin(pts), end(pts)) - begin(pts));
	if(pts.size() <= 1) return pts;

	int s=0, n=pts.size();
	vector<PT> h(2*n+1);

	for(int i=0; i<n; h[s++] = pts[i++])
		while(s > 1 && h[s-2].cross(pts[i], h[s-1]) >= 0 )
			s--;

	for(int i=n-2, t=s; ~i; h[s++] = pts[i--])
		while(s > t && h[s-2].cross(pts[i], h[s-1]) >= 0 )
			s--;

	h.resize(s-1);
	return h;
}

bool onSegment(PT s, PT e, PT p){ 
	return p.cross(s, e) == 0 && (s-p) * (e-p) <= 0;
}

bool isInside(const vector<PT>& h, PT p, bool strict = true){
	int a = 1, b = h.size() - 1, r = !strict;
	if(h.size() < 3) return r && onSegment(h[0], h.back(), p);
	if(h[0].cross(h[a], h[b]) > 0) swap(a, b);
	if(h[0].cross(h[a], p) >= r || h[0].cross(h[b], p) <= -r) return false;
	while(abs(a-b) > 1){
		int c = (a + b) / 2;
		if(h[0].cross(h[c], p) > 0) b = c;
		else a = c;
	}
	return h[a].cross(h[b], p) < r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, m, q; cin >> n >> m >> q;

    int c = 1;

    vector<PT> h1, h2;
    PT p;
    
    while(n != 0 || m != 0 || q != 0) {
        vector<PT> a(n), b(m);

        for (auto &[x, y] : a) cin >> x >> y;
        for (auto &[x, y] : b) cin >> x >> y; 
        
        h1 = ConvexHull(a), h2 = ConvexHull(b);

        cout << "Data set " << c++ << ":\n";
        
        for (int i = 0; i < q; i++) {
            cin >> p.x >> p.y;
            
            if (n > 2 && isInside(h1, p, false)) 
                cout << "     Citizen at (" << p.x << "," << p.y << ") is safe.\n";
            else if (m > 2 && isInside(h2, p, false)) 
                cout << "     Citizen at (" << p.x << "," << p.y << ") is robbed.\n"; 
            else
                cout << "     Citizen at (" << p.x << "," << p.y << ") is neither.\n";
        }
        cout << '\n';
        cin >> n >> m >> q;
    }

    return 0;
}