#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n" 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s;
    int n; cin >> n;
    int solved = -1;
    for (int i = 0; i + 6 < s.size(); i++){
        if (s[i] == 'd'){
            if (s[i + 1] == 'e'){
                if (s[i + 2] == 's'){
                    if (s[i + 3] == 'm'){
                        if (s[i + 4] == 'o'){
                            if (s[i + 5] == 'n'){
                                if (s[i + 6] == 'd'){
                                    solved = 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for (int j = 0; j < n; j++){
        int pos; cin >> pos; pos--;
        int wordPos = pos + 1;
        char c; cin >> c;
        if (solved == -1){
            s[pos] = c;
            if (c == 'd') wordPos = 0;
            else if (c == 'e') wordPos = 1;
            else if (c == 's') wordPos = 2;
            else if (c == 'm') wordPos = 3;
            else if (c == 'o') wordPos = 4;
            else if (c == 'n') wordPos = 5;
            int i = pos - wordPos;
            if (i >= 0 && i + 6 < s.size()){
                if (s[i] == 'd'){
                    if (s[i + 1] == 'e'){
                        if (s[i + 2] == 's'){
                            if (s[i + 3] == 'm'){
                                if (s[i + 4] == 'o'){
                                    if (s[i + 5] == 'n'){
                                        if (s[i + 6] == 'd'){
                                            solved = j + 1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (wordPos == 0){
                wordPos = 6;
                i = pos - wordPos;
                if (i >= 0 && i + 6 < s.size()){
                    if (s[i] == 'd'){
                        if (s[i + 1] == 'e'){
                            if (s[i + 2] == 's'){
                                if (s[i + 3] == 'm'){
                                    if (s[i + 4] == 'o'){
                                        if (s[i + 5] == 'n'){
                                            if (s[i + 6] == 'd'){
                                                solved = j + 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        
    }
    if (solved == -1){
        cout << "Goodbye, my love!" << endl;
    } else {
        cout << "I love you, Desmond!" << endl;
        cout << solved << endl;
    }
    return 0;  
}