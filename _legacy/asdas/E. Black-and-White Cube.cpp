    #include <bits/stdc++.h>

    #define endl '\n'

    using namespace std;

    int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        int n; cin >> n;

        if (n % 2 == 0) {
            for (int k = 0; k < n; k++) {
                if (k% 2 == 1) {
                    for (int j = 0; j < n/2; j++) {
                        if (j % 2 == 1) {
                            for (int i = 0; i < n/2; i++) {
                                if (i % 2 == 1) cout << "bb";
                                else cout << "ww"; 
                            }
                            cout << endl;
                            for (int i = 0; i < n/2; i++) {
                                if (i % 2 == 1) cout << "bb";
                                else cout << "ww"; 
                            }
                            cout << endl;
                        }
                        else {
                            for (int i = 0; i < n/2; i++) {
                                if (i % 2 == 1) cout << "ww";
                                else cout << "bb"; 
                            }
                            cout << endl;
                            for (int i = 0; i < n/2; i++) {
                                if (i % 2 == 1) cout << "ww";
                                else cout << "bb"; 
                            }
                            cout << endl;
                        }
                    }
                }
                else {
                    for (int j = 0; j < n/2; j++) {
                        if (j % 2 == 1) {
                            for (int i = 0; i < n/2; i++) {
                                if (i % 2 == 1) cout << "ww";
                                else cout << "bb"; 
                            }
                            cout << endl;
                            for (int i = 0; i < n/2; i++) {
                                if (i % 2 == 1) cout << "ww";
                                else cout << "bb"; 
                            }
                            cout << endl;
                        }
                        else {
                            for (int i = 0; i < n/2; i++) {
                                if (i % 2 == 1) cout << "bb";
                                else cout << "ww"; 
                            }
                            cout << endl;
                            for (int i = 0; i < n/2; i++) {
                                if (i % 2 == 1) cout << "bb";
                                else cout << "ww"; 
                            }
                            cout << endl;
                        }
                    }
                }
                cout << endl;
            }
        }

        else cout << -1;

        return 0;
    }