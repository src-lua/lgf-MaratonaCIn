#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int  main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int spells; cin >> spells;
    vector<int> deff;
    vector<int> teff;
    for (int i = 0; i < spells; i++){
        int eff; cin >> eff;
        deff.push_back(eff);
    }
    for (int i = 0; i < spells; i++){
        int eff; cin >> eff;
        teff.push_back(eff);
    }
    int days; cin >> days;

    vector<pair<int,int>> dser;
    vector<pair<int,int>> tser;
    for (int i = 0; i < days; i++){
        int ser; cin >> ser;
        dser.push_back({ser,i});
    }
    for (int i = 0; i < days; i++){
        int ser; cin >> ser;
        tser.push_back({ser,i});
    }
    sort(dser.begin(), dser.end());
    sort(tser.begin(), tser.end());
    
    vector<int> desmondDaySpell (days, 1e5 + 5);
    vector<int> thorDaySpell (days, 1e5 + 5);
    int spindex = 0;
    for (int i = 0; i < dser.size(); i++){
        while (dser[i].first >= deff[spindex]){
            spindex++;
            if (spindex == spells){break;}
        }
        if (spindex < spells){
            desmondDaySpell[dser[i].second] = spindex;
        }
    }
    spindex = 0;
    for (int i = 0; i < tser.size(); i++){
        while (tser[i].first >= teff[spindex]){
            spindex++;
            if (spindex == spells){break;}
        }
        if (spindex < spells){
            thorDaySpell[tser[i].second] = spindex;
        }
    }
    for (int i = 0; i < days; i++){
        if (desmondDaySpell[i] < thorDaySpell[i]) cout << "Mike" << endl;
        else if (desmondDaySpell[i] > thorDaySpell[i]) cout << "Constantine" << endl;
        else cout << "Draw" << endl;
    }
}