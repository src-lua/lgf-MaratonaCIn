#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, t; cin >> n >> t;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> arr2(n);

    int answ = 0;
    int j = 0;
    int sum = 0;

    for (int i = 0; i < n; i++) {

        while(j < n && sum + arr[j] < t) {
            sum += arr[j];
            j++;
        }


        answ = max(answ, j-i);
        sum -= arr[i];
        j++;
    }
    
    cout << answ << endl;
    

    return 0;
}