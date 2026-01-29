/**
 * Author:      Lua
 * Problem:     G
 * Link:        https://vjudge.net/contest/782309#problem/G
 * Status:      AC
 * Created:     29-01-2026 11:06:02
 **/

#include <bits/stdc++.h>
#define endl '\n'
using ll = long long;
using namespace std;

struct MinQueue : deque<pair<int, int>> {
    int min(){ return front().first; }
    void push(int x){ 
        int cnt = 1;
        while(!empty() && x <= back().first)
            cnt += back().second, pop_back();
        push_back({x, cnt});
    }
    void pop(){ if(!--front().second) pop_front(); } 
};

int main() {
    ios::sync_with_stdio(false);cin.tie(0);

    int n, k; cin >> n >> k;

    ll x, a, b, c;
    cin >> x >> a >> b >> c;

    MinQueue mq;

    for(int i=0; i<k; i++){
        mq.push(x);
        x = (a*x + b) % c;
    }

    ll ans = mq.min();

    for(int i=k; i<n; i++){
        mq.push(x);
        mq.pop();
        ans ^= mq.min();
        x = (a*x + b) % c;
    }

    cout << ans << endl;
}