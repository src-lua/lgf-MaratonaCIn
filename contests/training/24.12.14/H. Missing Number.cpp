#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    int sz = log2(n);


    int x;
    int answ = 0;
    vector<int> arr;
    for (int i = 0; i < n; i++) arr.push_back(i);
    
    for (int k = sz; k >= 0; k--) {
        int target = (1 << (k));
        vector<int> zero;
        vector<int> one;
        
        for (int i = 0; i < arr.size(); i++) {
            cout << "? " << arr[i] + 1 << ' ' << k << endl;

            cin >> x;
            if (x == 0) zero.push_back(i);
            else one.push_back(i);

            if (zero.size() == target) {
                answ += (1 << k);

                vector<int> tmp;

                for(auto e: one) tmp.push_back(e);
                for (int j = i+1; j < arr.size(); j++) tmp.push_back(arr[j]);
                
                arr = tmp;

                break;
            }
            else if (one.size() == arr.size()+1-target) {
                vector<int> tmp;

                for(auto e: zero) tmp.push_back(e);
                for (int j = i+1; j < arr.size(); j++) tmp.push_back(arr[j]);
                
                arr = tmp;

                break;
            }
        }
    }

    cout << "! " << answ << endl;

    return 0;
}