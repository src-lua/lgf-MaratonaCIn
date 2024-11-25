#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    string s; cin >> s;
 
    map<char, int> frequence;
 
    for (auto c: s) {
        frequence[c]++;
    }
 
    bool HasOdd = false;
    string Odd;
 
    string answ;
 
    for (auto [key, value]: frequence) { 
        if (value%2 == 1 && HasOdd) {
            cout << "NO SOLUTION";
            return 0;
        }
 
        if (value%2 == 1) {
            HasOdd = true;
            for (int i = 0; i < value; i++) {
                Odd += key;
            }
            
        }
        
        else for (int i = 0; i < value/2; i++) {
            answ += key;
        }
    }
 
    cout << answ; cout << Odd; reverse(answ.begin(), answ.end()); cout << answ;
    
    return 0;
