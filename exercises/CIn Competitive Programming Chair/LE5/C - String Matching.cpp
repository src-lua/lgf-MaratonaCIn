#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

vector<int> pi(const string& s) {
	vector<int> p(s.size());
	for (int i = 1; i < s.size(); i++) {
		int g = p[i-1];
		while (g && s[i] != s[g]) g = p[g-1];
		p[i] = g + (s[i] == s[g]);
	}
	return p;
}

vector<int> match(const string& s, const string& pat) {
	vector<int> p = pi(pat + '\0' + s), res;
	for (int i = p.size()-s.size(); i < p.size(); i++)
		if (p[i] == pat.size()) res.push_back(i - 2 * pat.size());
	return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s;
    string t; cin >> t;

    cout << match(s, t).size() << endl;  

    return 0;
}