#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

struct TrieNode {
    TrieNode(int sz, bool isLeaf = false) : to(sz, nullptr), isLeaf(isLeaf) {}
    vector<TrieNode *> to;
    bool isLeaf;
};

class Trie{
    private:
    int size_;
    TrieNode * root;

    void insert(TrieNode* rt, string& value, int idx) {
        if (idx == value.size()) {
            rt->isLeaf = true;
            return;
        }

        int i = value[idx] - 'a';

        if (rt->to[i] == nullptr) rt->to[i] = new TrieNode(size_);
        
        return insert(rt->to[i], value, idx+1);
    }
    
    void search(TrieNode* rt, string& value, int idx, string& query) {
        if (idx >= value.size()) {
            if (rt->isLeaf && idx != value.size()) cout << query << endl;
            
            for (int i = 0; i < 26; i++) {
                if (rt->to[i] != nullptr) {
                    query += (i+'a');
                    search(rt->to[i], value, idx+1, query);
                    query.pop_back();
                }
            }
            
            return;
        }

        int i = value[idx] - 'a';

        if (rt->to[i] == nullptr) {
            cout << "No match." << endl;
            return;
        }

        query += (i+'a');
        return search(rt->to[i], value, idx+1, query);
    }
    
   public:
    Trie(int sz) : size_(sz) {
        root = new TrieNode(size_);
    }

    void insert(string v) { return insert(root, v, 0); }
    void search(string v) { string s = ""; search(root, v, 0, s); }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    Trie trie(26);

    int n; cin >> n;

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        trie.insert(s);
    }

    int q; cin >> q;

    int c = 0;
    for (int i = 0; i < q; i++) {
        cin >> s;
        cout << "Case #" << ++c << ": \n";
        trie.search(s);
    }
    
    return 0;
}