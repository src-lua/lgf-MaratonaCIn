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
    
    bool search(TrieNode* rt, string& value, int idx) {
        if (idx == value.size()) {
            if (rt->isLeaf ) return true;
            else return false;
        }

        int i = value[idx] - 'a';

        if (rt->to[i] == nullptr) return false;

        return search(rt->to[i], value, idx+1);
    }

    public:
    Trie(int sz) : size_(sz) {
        root = new TrieNode(size_);
    }

    void insert(string v) { return insert(root, v, 0); }
    bool search(string v) { return search(root, v, 0); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    Trie t(26);

    return 0;
}