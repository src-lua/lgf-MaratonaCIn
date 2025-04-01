#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

vector<pii> getFact(int n){
	vector<pii> primes;
	for(int p = 2; p*p <= n; p++){
		if(n % p == 0){
			int exp = 0;
			while(n % p == 0){
				exp++;
				n /= p;
			}
			primes.push_back({p,exp});
		}
	}
	if(n > 1) primes.push_back({n,1});
	return primes;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int c, d; cin >> c >> d;

    vector<int> fizz;
    vector<int> buzz;
    for(int i = c; i <= d; i++) {
        string s; cin >> s;
        if (s == "Fizz") {
            fizz.push_back(i);
        }

        if (s == "Buzz") {
            buzz.push_back(i);
        }

        if (s == "FizzBuzz") {
            fizz.push_back(i);
            buzz.push_back(i);
        }
    }

    map<int,int> nfizz;
    map<int,int> countf;
    map<int,int> nbuzz;
    map<int,int> countb;

    for (int i = 0; i < fizz.size(); i++) {
        vector<pii> f = getFact(fizz[i]);
        for (int j = 0; j < f.size(); j++) {
            auto [b,e] = f[j];

            if (nfizz.count(b) == 0) nfizz[b] = e;
            else nfizz[b] = min(nfizz[b], e);
            countf[b]++;
        }
    }

    for (int i = 0; i < buzz.size(); i++) {
        vector<pii> f = getFact(buzz[i]);
        for (int j = 0; j < f.size(); j++) {
            auto [b,e] = f[j];

            if (nbuzz.count(b) == 0) nbuzz[b] = e;
            else nbuzz[b] = min(nbuzz[b], e);
            countb[b]++;
        }
    }

    int fans = 1;
    int bans = 1;

    if (fizz.size() == 0) fans = d+1;
    if (buzz.size() == 0) bans = d+2;

    for(auto [k,v]:nfizz) {
        if (countf[k] == fizz.size())
        fans *= pow(k,v);
    }

    for(auto [k,v]:nbuzz) {
        if (countb[k] == buzz.size())
        bans *= pow(k,v);
    }

    cout << fans << " " << bans << endl;



    
    

}