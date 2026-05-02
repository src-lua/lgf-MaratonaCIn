/**
 * Author:      Lua
 * Problem:     F
 * Link:        https://codeforces.com/group/btcK4I5D5f/contest/689113/problem/F
 * Status:      ~
 * Created:     02-05-2026 08:53:00
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 998244353;

struct mll {
    ll val;
    mll(ll x = 0) : val(x) {}

    void read() { cin >> val; }

    mll operator+(mll o) { return (val + o.val) % MOD; }
    mll operator-(mll o) { return ((val - o.val) % MOD + MOD) % MOD; }
    mll operator*(mll o) { return (val * o.val) % MOD; }
    mll operator*=(mll o) { return (*this) =  (*this) * o; }
    mll operator%(int o) { return val % o; }
    mll operator/(mll o) { return (*this) * inv(o.val); }
    mll operator^(int i) {
        mll ans = 1;
        mll a(val);
        while(i) {
            if (i & 1) ans *= a;
            a *= a;
            i >>= 1;
        }
        return ans;
    }

    mll inv(mll x) { return x^(MOD-2); }

};

struct Matrix {
    mll x, y, z, w;

    Matrix(mll x = 1, mll y = 0, mll z = 0, mll w = 1) : x(x), y(y), z(z), w(w) {}

    const Matrix operator*(Matrix o) {
        auto [a,b,c,d] = o;
        Matrix ans;
        ans.x = x*a + y*c;
        ans.y = x*b + y*d;
        ans.z = z*a + w*c;
        ans.w = z*b + w*d;
        return ans;
    }

    Matrix operator *=(Matrix o) {
        return (*this) = (*this) * o;
    }

    Matrix operator^(int i) {
        Matrix ans;
        Matrix a = *this;
        while(i) {
            if (i & 1) ans *= a;
            a *= a;
            i >>= 1;
        }
        return ans;
    }
};

void solve() {
    mll a, b, n, m, fn, fm;
    a.read(), b.read();
    n.read(), m.read();
    fn.read(), fm.read();

    Matrix Base = {a, b, 1, 0};

    int i = (m - n).val;

    auto [a_, b_, c_, d_] = Base^i;

    mll k = (fm - (fn * d_)) / c_;
    mll k_ = k*a_ + fn*b_;

    auto [x, y, z, w] = Base^(m.val);

    mll f1 = ( (fm*y) - (k_*w) ) / ( (z*y) - (x*w) );
    mll f0 = ( k_ - (x*f1) ) / y;

    cout << f0.val << ' ' << f1.val << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tc; cin >> tc; while(tc--) solve();

    return 0;
}
