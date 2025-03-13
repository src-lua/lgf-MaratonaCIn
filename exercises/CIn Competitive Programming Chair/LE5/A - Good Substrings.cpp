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

    int solve(TrieNode* rt, int k, int i, string& s, string& t) {
        if (i > k) return 0;

        int answ = 1;
        
        for (int j = 0; j < size_; j++) {
            if (rt->to[j] != nullptr) {
                answ += solve(rt->to[j], k, i+(t[j]-'0'+1)%2, s, t);
            }
        }
        return answ;
    }

    public:
    Trie(int sz) : size_(sz) {
        root = new TrieNode(size_);
    }

    void insert(string& v) { return insert(root, v, 0); }
    int solve(int k, string& s, string & t) { return solve (root, k, 0, s, t) - 1; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s, t; cin >> s >> t;
    int k; cin >> k;

    Trie trie(26);

    // O(n^2)
    for (int i = 0; i < s.size(); i++) {
        string k = s.substr(i);
        trie.insert(k);
    }

    cout << trie.solve(k, s, t) << endl;

    return 0;
}