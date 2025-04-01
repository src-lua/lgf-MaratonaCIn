#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k; 
    cin >> n >> m >> k;

    vector<int> a(k);
    for (int i = 0; i < k; i++) cin >> a[i];

    long long int answ = 0;

    int x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> x;

            auto f = find(a.begin(), a.end(), x);
            answ += f - a.begin()+1;
            a.erase(f);
            a.insert(a.begin(), x);
        }
    }

    cout << answ << endl;

    return 0;
}