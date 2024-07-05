#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    string s;

    int ycount;
    int zcount;

    int dir;  // +x = 0 | -x = 1 | +y = 2 | -y = 3 | +z = 4 | -z = 5

    while (n) {
        ycount = zcount = dir = 0;

        for (int i = 1; i < n; i++) {
            cin >> s;

            if (s == "+y") {
                switch (dir) {
                case 0:
                    dir = 2;
                    break;
                case 1:
                    dir = 3;
                    break;
                case 2:
                    dir = 1;
                    break;
                case 3:
                    dir = 0;
                    break;
               }
                
            } 
            
            else if (s == "-y") {
                switch (dir) {
                case 0:
                    dir = 3;
                    break;
                case 1:
                    dir = 2;
                    break;
                case 2:
                    dir = 0;
                    break;
                case 3:
                    dir = 1;
                    break;
                }
                
            }
            
            else if (s == "+z") {
                switch (dir) {
                case 0:
                    dir = 4;
                    break;
                case 1:
                    dir = 5;
                    break;
                case 4:
                    dir = 1;
                    break;
                case 5:
                    dir = 0;
                    break;
                }
            }
            
            else if (s == "-z") {
                switch (dir) {
                case 0:
                    dir = 5;
                    break;
                case 1:
                    dir = 4;
                    break;
                case 4:
                    dir = 0;
                    break;
                case 5:
                    dir = 1;
                    break;
                }
            }
        }

        switch (dir) {
        case 0:
            cout << "+x" << endl;
            break;
        case 1:
            cout << "-x" << endl;
            break;
        case 2:
            cout << "+y" << endl;
            break;
        case 3:
            cout << "-y" << endl;
            break;
        case 4:
            cout << "+z" << endl;
            break;
        case 5:
            cout << "-z" << endl;
            break;
        }

        cin >> n;
    }

    return 0;
}