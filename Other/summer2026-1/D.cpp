/**
 * Author:      Lua
 * Problem:     D
 * Link:        https://vjudge.net/contest/781528#problem/D
 * Status:      AC
 * Created:     28-01-2026 16:15:44
 **/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    return 0;
}
#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;
const int mxn = 3e4;
const int mxm = 1e6 + 5;
const int B = sqrt(mxn) + 1;
struct query {
    int l, r, id;
    bool operator<(query other) const {
        return make_pair(l / B, ((l / B) & 1) ? -r : r) <
               make_pair(other.l / B, ((other.l / B) & 1) ? -other.r : other.r);
    }
};
int n;
vector<int> val(mxn);
vector<int> freq(mxm, 0);
int ans = 0;
void add(int id) {
    freq[val[id]]++;
    if (freq[val[id]] == 1) ans++;
}
void rem(int id) {
    freq[val[id]]--;
    if (freq[val[id]] == 0) ans--;
}
int get_ans() { return ans; }
vector<int> MO(vector<query> query) {
    sort(query.begin(), query.end());
    vector<int> resp(query.size());
    int l = 0, r = -1;
    for (auto [nl, nr, idx] : query) {
        while (l > nl) add(--l);
        while (r < nr) add(++r);
        while (l < nl) rem(l++);
        while (r > nr) rem(r--);
        resp[idx] = get_ans();
    }
    return resp;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> val[i];
    int q;
    cin >> q;
    vector<query> qr;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        qr.push_back({l, r, i});
    }
    vector<int> resp = MO(qr);
    for (int i : resp) cout << i << "\n";
    return 0;
}