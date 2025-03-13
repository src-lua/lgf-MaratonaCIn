    #include <bits/stdc++.h>

    #define endl '\n'

    using namespace std;

    int solve() {

        int n; cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        
        sort(arr.begin(), arr.end());
        vector<int> prefix(n+1);
        prefix[0] = 0;
        for (int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] + arr[i];
        }

        if (arr[0] != 1) {
            cout << "NO\n";
            return 0;
        }

        for (int i = 1; i < n; i++) {
            bool flag = false;
            
            for (int j = 1; j <= i; j++) {
                if (*lower_bound(prefix.begin(), prefix.end(), prefix[j]-arr[i]) == prefix[j]-arr[i]) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                cout << "NO\n";
                return 0;
            }
        }

        cout << "YES\n";

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