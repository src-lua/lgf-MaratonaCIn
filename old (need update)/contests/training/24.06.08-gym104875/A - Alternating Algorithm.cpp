#include <bits/stdc++.h>

using namespace std;
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<int> arr(n+1);
    
    for (int i = 0; i <= n; i++) {
        cin >> arr[i];
    }

    bool flag1 = true, flag2 = true, flag3 = true;
    int c = 0;
    int k = 0;

    while (flag1 || flag2) {


        if (c % 2 == 0) {
            flag1 = false; 
            for (int i = 0; i < n; i+=2) {
                if (arr[i] > arr[i+1]) {
                    swap(arr[i], arr[i+1]);
                    flag1 = true;
                    flag2 = true;
                }
            }
        }

        if (c % 2 == 1) {
            flag2 = false;
            for (int i = 1; i < n; i+=2) {
                if (arr[i] > arr[i+1]) {
                    swap(arr[i], arr[i+1]);
                    flag1 = true;
                    flag2 = true;
                }
            }
        }

        c++;
    }

    cout << c-2;

}