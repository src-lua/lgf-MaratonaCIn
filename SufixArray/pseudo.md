```c++
function SuffixArray(string s) {
    s = s + "$";
    int n = s.size();
    array p(n), c(n);

    {
        // iteration k = 0
        array a(n);
        for every i from 0 -> n: a[i] = {s[i], i};

        sort(a);

        for every i from 0 -> n: p[i] = a[i].second;

        c[p[0]] = 0;

        for every i from 1 -> n:
            if (a[i].left == a[i-1].left) c[p[i]] = c[p[i-1]];
            else c[p[i]] = c[p[i-1]] + 1;
    }

    int k = 0;
    while (power(2, k) < n):
        // transition k -> k + 1
        for every i from 0 -> n: p[i] = (p[i] - power(2,k)) % n;

        count_sort(p, c); // Sorts P based on C
        array new_c;

        new_c[p[0]] = 0;

        for every i from 1 -> n:
            pair prv = { c[p[i]-1], c[(p[i-1] + power(2,k)) % n]}
            pair now = { c[p[i]],   c[(p[i]   + power(2,k)) % n]}
            if (now == prv) new_c[p[i]] = new_c[p[i-1]];
            else new_c[p[i]] = new_c[p[i-1]] + 1;
        c = new_c;
        k++;

    return p;
```

```c++
function SuffixArray(string s) {
    s = s + "$";
    int n = s.size();
    array p(n), c(n);

    {
        // iteration k = 0
        array a(n);
        for every i from 0 -> n: a[i] = {s[i], i};

        sort(a);

        for every i from 0 -> n: p[i] = a[i].second;

        c[p[0]] = 0;

        for every i from 1 -> n:
            if (a[i].left == a[i-1].left) c[p[i]] = c[p[i-1]];
            else c[p[i]] = c[p[i-1]] + 1;
    }

    int k = 0;
    while (power(2, k) < n):
        // transition k -> k + 1

        array a(n);
        for every i from 0 -> n: a[i] = { {c[p[i]], cp[[i + power(2,k) % n]]}, i};

        sort(a);

        for every i from 0 -> n: p[i] = a[i].second.second;

        c[p[0]] = 0;

        for every i from 1 -> n:
            if (a[i].left == a[i-1].left) c[p[i]] = c[p[i-1]];
            else c[p[i]] = c[p[i-1]] + 1;
        k++;

    return p;
```

```c++
function SuffixArray(string s) {
    s = s + "$";
    int n = s.size();
    array p(n), c(n);

    {
        // iteration k = 0
        array a(n);
        for every i from 0 -> n: a[i] = {s[i], i};

        sort(a);

        for every i from 0 -> n: p[i] = a[i].second;

        c[p[0]] = 0;

        for every i from 1 -> n:
            if (a[i].left == a[i-1].left) c[p[i]] = c[p[i-1]];
            else c[p[i]] = c[p[i-1]] + 1;
    }

    int k = 0;
    while (power(2, k) < n):
        // transition k -> k + 1

        array a(n);
        for every i from 0 -> n: a[i] = { {c[p[i]], cp[[i + power(2,k) % n]]}, i};

        radix_sort(a);

        for every i from 0 -> n: p[i] = a[i].second.second;

        c[p[0]] = 0;

        for every i from 1 -> n:
            if (a[i].left == a[i-1].left) c[p[i]] = c[p[i-1]];
            else c[p[i]] = c[p[i-1]] + 1;
        k++;

    return p;
```

```cpp
function radix_sort(array arr):
    int n = arr.size();
    array new_arr(n);
    {
        array cnt(n);
        for every e in arr: cnt[e.class.right]++; // Generate buckets size

        array pos(n); pos[0] = 0;
        for every i from 1 -> n: pos[i] = pos[i-1] + cnt[i-1]; // Generate buckets index
        
        for every e in arr:
            
            idx = e.class.right;
            new_arr[pos[idx]] = e;
            pos[idx]++;
    }
    {
        array<int> cnt(n);
        for every e in new_arr: cnt[e.class.left]++; // Generate buckets size
        
        array<int> pos(n); pos[0] = 0;
        for every i from 1 -> n: pos[i] = pos[i-1] + cnt[i-1]; // Generate buckets index
                
        for every e in new_arr:
            idx = e.class.left;
            arr[pos[idx]] = e;
            pos[idx]++;
    }
```

```cpp
function count_sort(array p, array c):
    int n = arr.size();

    array new_p(n);
    array cnt(n);

    for every e in c: cnt[e]++; // Generate buckets size

    array pos(n); pos[0] = 0;
    for every i from 1 -> n: pos[i] = pos[i-1] + cnt[i-1]; // Generate buckets index
    
    for every e in p:
        idx = c[e];
        new_p[pos[idx]] = e;
        pos[idx]++;
    p = new_p
```
```cpp
function lowerBound(int l, int r, array p, string s, string t):
    int answ = r+1;
    while l <= r:
        int m = l + (r - l) / 2;
        string substring = s[p[m] ... t.size()]

        if (substring < t):
            l = m + 1;
        else:
            r = m - 1;
            answ = m;
    return answ;

function upperBound(int l, int r, array p, string s, string t):
    int answ = r+1;
    while l <= r:
        int m = l + (r - l) / 2;
        string substring = s[p[m] ... t.size()]

        if (substring <= t):
            l = m + 1;
        else:
            r = m - 1;
            answ = m;
    return answ;

function get_substrings(string s, string t, array p):
    int l = lowerBound(0, p.size()-1, p, s, t);
    int u = upperBound(0, p.size()-1, p, s, t);

    if (l < p.size() && s.substr(p[l], t.size()) == t) return u - l; 
    return 0;

function lcp(vector<int>& p, vector<int>& c, string& s):
    int n = p.size();
    array l(n);

    int k = 0;
    for every i from 0 -> n-1:
        int posi = c[i];
        int j = p[posi-1];
        
        while (s[i+k] == s[j+k]): k++;
        l[posi] = k;
        k = max(k-1, 0);

    return l;


function lcs(array p, array l, string st, int m) { // m = s.size()
    int mx = 0;
    string lcs = "";
    for every i from 1 -> l.size():
        int i_group = (0 <= p[i] && p[i] < m);
        int j_group = (0 <= p[i - 1] && p[i - 1] < m);

        if (i_group != j_group):
            if (mx < l[i]):
                mx = l[i];
                lcs = st.substr(p[i], mx);
    return lcs;
```

```cpp
struct TrieNode:
    constructor TrieNode(int sz): 
        to = array(sz);

    array to;

class Trie:
    private: int size_;
    private: TrieNode root;

    public: constructor Trie(int sz):
        size_ = sz;
        root = new TrieNode(size_);

    public: function insert(string v) { return insert(root, v, 0); }
    public: function search(string v) { return search(root, v, 0); }

private: function insert(TrieNode rt, string value, int idx):
    if (idx == value.size()):
        rt->isLeaf = true;
        return;

    int i = value[idx] - 'a';

    if (rt->to[i] == nullptr): rt->to[i] = new TrieNode(size_);
    
    return insert(rt->to[i], value, idx+1);


private: function search(TrieNode rt, string value, int idx):
    if (idx == value.size()):
        if (rt->isLeaf ) return true;
        else return false;

    int i = value[idx] - 'a';

    if (rt->to[i] == nullptr): return false;

    return search(rt->to[i], value, idx+1);

};
```