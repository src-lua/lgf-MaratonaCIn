#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

struct TrieNode {
    map<int, TrieNode *> to;
    int substr = 0;
};

class Trie{
    private:
    int size_;
    TrieNode * root;

    void insert(TrieNode* rt, string& value, int idx) {
        rt->substr++;
        if (idx == value.size()) {
            return;
        }

        int i = value[idx] - 'a';

        if (rt->to[i] == nullptr) rt->to[i] = new TrieNode();
        
        return insert(rt->to[i], value, idx+1);
    }
    
    int search(TrieNode* rt, string& value, int idx) {
        if (idx >= value.size()) {
            return rt->substr;
        }

        int i = value[idx] - 'a';

        if (rt->to[i] == nullptr) {
            return 0;
        }

        return search(rt->to[i], value, idx+1);
    }
    
   public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string v) { return insert(root, v, 0); }
    int  search(string v) { return search(root, v, 0); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    Trie trie;

    int n; int q; cin >> n >> q;

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        trie.insert(s);
    }

    for (int i = 0; i < q; i++) {
        cin >> s;
        cout << trie.search(s) << endl;
    }

    return 0;
}