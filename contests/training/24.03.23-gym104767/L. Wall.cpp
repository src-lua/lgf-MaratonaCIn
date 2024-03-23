#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

void print(string& s) {
    int len = s.size();

    for (int i = 1; i < len-1; i++) {
        if (s[i] == '0') cout << '.';
        else cout << 'X';    
    }
}

int binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;
 
    int base = 1;
 
    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;
 
        dec_value += last_digit * base;
 
        base = base * 2;
    }
 
    return dec_value;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int rule, gens; cin >> rule >> gens;

    string s2; cin >> s2;

    int len = s2.size();

    vector<string> s(2);
    s[0] = "0";
    for (int i = 0; i < len; i++) {
        if (s2[i] == '.') s[0] += '0';
        else s[0] += '1';
    }
    s[0] += '0';
    
    s[1] = s[0];


    for (int tc = 0; tc < gens; tc++) {

        len = s[tc%2].size();

        for (int i = 1; i < len-1; i++) {
            string k = ""; k += s[tc%2][i-1]; k += s[tc%2][i]; k += s[tc%2][i+1];
            int mask = binaryToDecimal(stoi(k));

            if (rule & (1<<mask)) {
                s[(tc+1)%2][i] = '1';
            } else s[(tc+1)%2][i] = '0';

        }

        print(s[(tc+1)%2]); if (tc != gens-1) cout << endl;
    }

    return 0;
}