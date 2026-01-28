#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

class node {
  public:
    vector<node*> sons;


        int size() {
            if (this->_size != -1) return this->_size;
            
            this->_size = 1;

            for (auto e : this->sons) {
                this->_size += e->size();
            }

            return this->_size;
    }

  private:
    int _size = -1;

};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<int> parent(n);
    parent[0] = -1;

    vector<node> tree(n, node());
    for (int i = 1; i < n; i++) {
        cin >> parent[i];
        parent[i]--;

        tree[parent[i]].sons.push_back(&tree[i]);
    }
    
    for (int i = 0; i < n; i++) {
        cout << tree[i].size()-1 << ' ';
    }

    cout << endl;

    return 0;
}