#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> lll;
typedef tuple<int,int,int> iii;

#define endll '\n';

int INF = INT_MAX;
long long INFF = LLONG_MAX;
int dirx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
int diry[8] = {0, 1, -1, 0, -1, 1, -1, 1};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, p; cin >> n >> p;

    int mx = 0;

    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a <= p) mx = max(a,mx);
    }

    cout << mx << endll;

}