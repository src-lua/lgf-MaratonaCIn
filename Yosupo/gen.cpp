#include <algorithm>
#include <array>
#include <cassert>
#include <cstdint>
#include <numeric>
#include <random>
#include <set>

struct Random {
  private:
    // Use xoshiro256**
    // References: http://xoshiro.di.unimi.it/xoshiro256starstar.c
    static uint64_t rotl(const uint64_t x, int k) {
        return (x << k) | (x >> (64 - k));
    }

    std::array<uint64_t, 4> s;

    uint64_t next() {
        const uint64_t result_starstar = rotl(s[1] * 5, 7) * 9;

        const uint64_t t = s[1] << 17;

        s[2] ^= s[0];
        s[3] ^= s[1];
        s[1] ^= s[2];
        s[0] ^= s[3];

        s[2] ^= t;

        s[3] = rotl(s[3], 45);

        return result_starstar;
    }

    // random choice from [0, upper]
    uint64_t next(uint64_t upper) {
        if (!(upper & (upper + 1))) {
            // b = 00..0011..11
            return next() & upper;
        }
        int lg = 63 - __builtin_clzll(upper);
        uint64_t mask = (lg == 63) ? ~0ULL : (1ULL << (lg + 1)) - 1;
        while (true) {
            uint64_t r = next() & mask;
            if (r <= upper)
                return r;
        }
    }

  public:
    Random(uint64_t seed = 0) {
        // Use splitmix64
        // Reference: http://xoshiro.di.unimi.it/splitmix64.c
        for (int i = 0; i < 4; i++) {
            uint64_t z = (seed += 0x9e3779b97f4a7c15);
            z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9;
            z = (z ^ (z >> 27)) * 0x94d049bb133111eb;
            s[i] = z ^ (z >> 31);
        }
    }

    // random choice from [lower, upper]
    template <class T>
    T uniform(T lower, T upper) {
        assert(lower <= upper);
        return T(lower + next(uint64_t(upper - lower)));
    }

    // random choice from false or true
    bool uniform_bool() { return uniform(0, 1) == 1; }

    // random choice from [0.0, 1.0]
    double uniform01() {
        uint64_t v = next(1ULL << 63);
        return double(v) / (1ULL << 63);
    }

    // random choice non-empty sub-interval from interval [lower, upper)
    // equal: random choice 2 disjoint elements from [lower, upper]
    template <class T>
    std::pair<T, T> uniform_pair(T lower, T upper) {
        assert(upper - lower >= 1);
        T a, b;
        do {
            a = uniform(lower, upper);
            b = uniform(lower, upper);
        } while (a == b);
        if (a > b) std::swap(a, b);
        return {a, b};
    }

    // generate random lower string that length = n
    std::string lower_string(size_t n) {
        std::string res = "";
        for (size_t i = 0; i < n; i++) {
            res += uniform('a', 'z');
        }
        return res;
    }

    // random shuffle
    template <class Iter>
    void shuffle(Iter first, Iter last) {
        if (first == last) return;
        // Reference and edit:
        // cpprefjp - C++日本語リファレンス
        // (https://cpprefjp.github.io/reference/algorithm/shuffle.html)
        int len = 1;
        for (auto it = first + 1; it != last; it++) {
            len++;
            int j = uniform(0, len - 1);
            if (j != len - 1)
                iter_swap(it, first + j);
        }
    }

    // generate random permutation that length = n
    template <class T>
    std::vector<T> perm(size_t n) {
        std::vector<T> idx(n);
        std::iota(idx.begin(), idx.end(), T(0));
        shuffle(idx.begin(), idx.end());
        return idx;
    }

    // random choise n elements from [lower, upper]
    template <class T>
    std::vector<T> choice(size_t n, T lower, T upper) {
        assert(T(n) <= upper - lower + 1);
        std::set<T> res;
        while (res.size() < n) res.insert(uniform(lower, upper));
        return {res.begin(), res.end()};
    }
} global_gen;

#include <cassert>
#include <iostream>
#include <tuple>
#include <vector>

#include <algorithm>
#include <cassert>
#include <climits>
#include <utility>
#include <vector>

template <class MonoidX, class MonoidF, class Action>
struct lazy_propagation_segment_tree {
    typedef typename MonoidX::value_type value_type;
    typedef typename MonoidF::value_type operator_type;
    const MonoidX mon_x;
    const MonoidF mon_f;
    const Action act;
    int n;
    std::vector<value_type> a;
    std::vector<operator_type> f;

    lazy_propagation_segment_tree() = default;
    lazy_propagation_segment_tree(int n_, const MonoidX & mon_x_ = MonoidX(), const MonoidF & mon_f_ = MonoidF(), const Action & act_ = Action())
            : mon_x(mon_x_), mon_f(mon_f_), act(act_) {
        n = 1; while (n < n_) n *= 2;
        a.resize(2 * n - 1, mon_x.unit());
        f.resize(n - 1, mon_f.unit());
    }
    template <class InputIterator>
    lazy_propagation_segment_tree(InputIterator first, InputIterator last, const MonoidX & mon_x_ = MonoidX(), const MonoidF & mon_f_ = MonoidF(), const Action & act_ = Action())
            : mon_x(mon_x_), mon_f(mon_f_), act(act_) {
        int size = std::distance(first, last);
        n = 1; while (n < size) n *= 2;
        a.resize(2 * n - 1, mon_x.unit());
        f.resize(n - 1, mon_f.unit());
        std::copy(first, last, a.begin() + (n - 1));
        for (int i = n - 2; i >= 0; -- i) {
            a[i] = mon_x.mult(a[2 * i + 1], a[2 * i + 2]);
        }
    }

    void range_apply(int l, int r, operator_type g) {
        assert (0 <= l and l <= r and r <= n);
        range_apply(0, 0, n, l, r, g);
    }
    void range_apply(int i, int il, int ir, int l, int r, operator_type g) {
        if (l <= il and ir <= r) { // 0-based
            a[i] = act(g, a[i]);
            if (i < (int)f.size()) f[i] = mon_f.mult(g, f[i]);
        } else if (ir <= l or r <= il) {
            // nop
        } else {
            range_apply(2 * i + 1, il, (il + ir) / 2, 0, n, f[i]);
            range_apply(2 * i + 2, (il + ir) / 2, ir, 0, n, f[i]);
            f[i] = mon_f.unit();  // unnecessary if the oprator monoid is commutative
            range_apply(2 * i + 1, il, (il + ir) / 2, l, r, g);
            range_apply(2 * i + 2, (il + ir) / 2, ir, l, r, g);
            a[i] = mon_x.mult(a[2 * i + 1], a[2 * i + 2]);
        }
    }

    value_type range_get(int l, int r) {
        assert (0 <= l and l <= r and r <= n);
        if (l == 0 and r == n) return a[0];
        value_type lacc = mon_x.unit(), racc = mon_x.unit();
        for (int l1 = (l += n), r1 = (r += n) - 1; l1 > 1; l /= 2, r /= 2, l1 /= 2, r1 /= 2) {  // 1-based loop, 2x faster than recursion
            if (l < r) {
                if (l % 2 == 1) lacc = mon_x.mult(lacc, a[(l ++) - 1]);
                if (r % 2 == 1) racc = mon_x.mult(a[(-- r) - 1], racc);
            }
            lacc = act(f[l1 / 2 - 1], lacc);
            racc = act(f[r1 / 2 - 1], racc);
        }
        return mon_x.mult(lacc, racc);
    }
};

struct min_max_monoid {
    struct value_type {
        long long min;
        long long max;
    };
    value_type unit() const {
        return (value_type) { LLONG_MAX, LLONG_MIN };
    }
    value_type mult(value_type a, value_type b) const {
        return (value_type) { std::min(a.min, b.min), std::max(a.max, b.max) };
    }
};

struct chmin_chmax_add_monoid {
    // lambda x: min(a, max(b, c + x))
    struct value_type {
        long long chmin;
        long long chmax;
        long long add;
    };
    value_type unit() const {
        return (value_type) { LLONG_MAX, LLONG_MIN, 0ll };
    }
    value_type mult(value_type a, value_type b) const {
        value_type c = b;
        // add
        if (c.chmin != LLONG_MAX) {
            c.chmin += a.add;
        }
        if (c.chmax != LLONG_MIN) {
            c.chmax += a.add;
        }
        c.add += a.add;
        // chmax
        c.chmin = std::max(a.chmax, c.chmin);
        c.chmax = std::max(a.chmax, c.chmax);
        // chmin
        c.chmin = std::min(a.chmin, c.chmin);
        return c;
    }
};

struct chmin_chmax_add_min_max_action {
    typedef typename chmin_chmax_add_monoid::value_type F;
    typedef typename min_max_monoid::value_type X;
    X operator () (F f, X x) const {
        if (x.min == LLONG_MAX) {
            assert (x.max == LLONG_MIN);
            return x;
        }
        X y;
        y.min = std::min(f.chmin, std::max(f.chmax, f.add + x.min));
        y.max = std::min(f.chmin, std::max(f.chmax, f.add + x.max));
        return y;
    }
};

typedef lazy_propagation_segment_tree<min_max_monoid, chmin_chmax_add_monoid, chmin_chmax_add_min_max_action> chmin_chmax_add_min_max_segment_tree;

using namespace std;

const long long A_ABS_MAX = 1'000'000'000'000;
const long long N_AND_Q_MAX = 200'000;

int main(int, char* argv[]) {
    long long seed = 1;
    auto gen = Random(seed);

    assert (0 <= seed and seed < 10);
    int n = seed + 1;  // use the seed, which is an index in the test set, to check n = 2^k - 1, 2^k, 2^k + 1
    int q = 20;
    printf("%d %d\n", n, q);
    vector<typename min_max_monoid::value_type> init(n);
    for (int i = 0; i < n; i++) {
        long long a = gen.uniform<long long>(-A_ABS_MAX, A_ABS_MAX);
        printf("%lld", a);
        if (i != n - 1) printf(" ");
        init[i] = { a, a };
    }
    printf("\n");
    chmin_chmax_add_min_max_segment_tree segtree(init.begin(), init.end());

    for (int i = 0; i < q; i++) {
        int t = gen.uniform(0, 3);
        int l, r;
        tie(l, r) = gen.uniform_pair(0, n);
        if (t == 0) {
            long long b = gen.uniform<long long>(-A_ABS_MAX, A_ABS_MAX);
            printf("%d %d %d %lld\n", t, l, r, b);
            segtree.range_apply(l, r, (typename chmin_chmax_add_monoid::value_type) { b, LLONG_MIN, 0ll });
        } else if (t == 1) {
            long long b = gen.uniform<long long>(-A_ABS_MAX, A_ABS_MAX);
            printf("%d %d %d %lld\n", t, l, r, b);
            segtree.range_apply(l, r, (typename chmin_chmax_add_monoid::value_type) { LLONG_MAX, b, 0ll });
        } else if (t == 2) {
            auto c = segtree.range_get(0, n);
            long long b = gen.uniform<long long>(-A_ABS_MAX - c.min, A_ABS_MAX - c.max);
            segtree.range_apply(l, r, (typename chmin_chmax_add_monoid::value_type) { LLONG_MAX, LLONG_MIN, b });
            printf("%d %d %d %lld\n", t, l, r, b);
        } else {
            printf("%d %d %d\n", t, l, r);
        }
    }
    return 0;
}