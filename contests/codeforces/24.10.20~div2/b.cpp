    #include <bits/stdc++.h>

    #define endl '\n'

    using namespace std;
    using ll = long long;

    int next(int pos, vector<ll>& arr) {
        for (int i = pos; i < arr.size(); i++) {
            if (arr[i] != arr[pos]) return i;
        }

        return -1;
    }

    int solve() {

        ll n, k; cin >> n >> k;
        ll N = n;

        vector<ll> arr(n+1);

        int zeros = 0;

        arr[0] = -1;

        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());
        
        int rnd = 0;

        int idx = 0;

        long long int answ = 0;

        while(k > 0) {
            idx = next(idx, arr);

            k -= (n-zeros) * (arr[idx]-rnd);

            answ += n + (arr[idx]-rnd- 1) * (n-zeros);
            rnd = arr[idx];
            n -= zeros;
            zeros = 0;

            for (int i = idx; i <= N; i++) {
                if (arr[i] != arr[idx]) break;
                zeros++;
            }
        }

        cout << answ+k << endl;

        return 0;
    }

    int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        int tc; cin >> tc; while (tc--) {
            solve();
        }

        return 0;
    }