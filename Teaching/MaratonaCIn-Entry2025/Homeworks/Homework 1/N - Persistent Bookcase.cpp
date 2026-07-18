#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using pii = pair<int,int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q; cin >> n >> m >> q;

    map<int, pair<int,bool>> IDs;
    int curr_id = 0;

    vector<vector<bool>> bookshelfs;
    vector<int> shelf_size(1e3, 0);

    int op, i, j;
    for (int _ = 0; _ < q; _++) {
        cin >> op;

        if (op == 1) {
            cin >> i >> j;
            if (IDs.count(i) == 0) {
                bookshelfs.push_back(vector<bool>(1e3, false));
                IDs[i] = {curr_id, true};
                curr_id++;
            }

            auto [id, book] = IDs[i];

            shelf_size[i]++;
            if (bookshelfs[id] == )

        } else

        if (op == 2) {

        } else

        if (op == 3) {

        } else

        if (op == 4) {

        }
        
    }
    

    return 0;
}