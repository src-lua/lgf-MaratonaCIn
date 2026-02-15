### 🚀 Cheat Sheet: Upsolving SegTrees Avançadas

**Ordem sugerida para contest (progressão didática):**

#### 1️⃣ Warm-up: Técnicas na Segtree Básica

| # | Problema | Tópico Principal | 💡 Dica / Ponto de Atenção | Solução |
| :---: | :--- | :--- | :--- | :---: |
| **A** | [**CSES 1143** — Hotel Queries](https://cses.fi/problemset/task/1143/) | Walk / Binary Search | Busca binária na seg tree; primeiro índice onde `max >= x`. | [Online](https://cses.fi/problemset/result/16177777/) • [Local](../../CSES/1143.cpp) |
| **B** | [**CSES 1190** — Subarray Sum Queries](https://cses.fi/problemset/task/1190/) | Max Subarray Sum | Manter `ans`, `pre`, `suf`, `sum` em cada nó; merge clássico. | [Online](https://cses.fi/problemset/result/16177505/) • [Local](../../CSES/1190.cpp) |

#### 2️⃣ Lazy Propagation: Do Básico ao Avançado

| # | Problema | Tópico Principal | 💡 Dica / Ponto de Atenção | Solução |
| :---: | :--- | :--- | :--- | :---: |
| **C** | [**CSES 1651** — Range Update Queries](https://cses.fi/problemset/task/1651/) | Lazy Propagation | Conceito base (Dual Segtree). | [Online](https://cses.fi/problemset/result/16153274/) • [Local](../../CSES/1651.cpp) |
| **D** | [**CF Gym 101741J** — Subsequence Sum Queries](https://codeforces.com/gym/101741/problem/J) | Counting / DP | Contar subsequências com soma ≡ k (mod m); merge multiplica contagens. | [Online](https://codeforces.com/gym/101741/submission/362189939) • [Local](../../Codeforces/Problemset/gym101741J.cpp) |
| **E** | [**CF 52C** — Circular RMQ](https://codeforces.com/contest/52/problem/C) | Circular RMQ | Tratar array circular (mod) + input chato. | [Online](https://codeforces.com/contest/52/submission/361404259) • [Local](../../Codeforces/Problemset/52C.cpp) |
| **F** | [**CF 718C** — Sasha and Array](https://codeforces.com/contest/718/problem/C) | Matrizes / Fib | Merge de matrizes 2x2. **Cuidado com TLE:** Não use `std::vector` na struct. | [Online](https://codeforces.com/contest/718/submission/361404574) • [Local](../../Codeforces/Problemset/718C.cpp) |
| **G** | [**CSES 1736** — Polynomial Queries](https://cses.fi/problemset/task/1736/) | Lazy Avançada | Update em P.A. / Função Afim. | [Online](https://cses.fi/problemset/result/16153434/) • [Local](../../CSES/1736.cpp) |
| **H** | [**Yosupo** — Range Affine Range Sum](https://judge.yosupo.jp/problem/range_affine_range_sum) | Lazy Multi-op | Composição de operações ($Ax + B$). | [Online](https://judge.yosupo.jp/submission/350194) • [Local](../../Yosupo/range_affine_range_sum.cpp) |

#### 3️⃣ Técnicas Especiais

| # | Problema | Tópico Principal | 💡 Dica / Ponto de Atenção | Solução |
| :---: | :--- | :--- | :--- | :---: |
| **I** | [**CF 915E** — Physical Education Lessons](https://codeforces.com/contest/915/problem/E) | Seg Dinâmica | **Cuidado com MLE:** Esparsa pode estourar; Compressão de coord. é mais seguro. | [Online](https://codeforces.com/contest/915/submission/361410789) • [Local](../../Codeforces/Problemset/915E.cpp) |
| **J** | [**SPOJ SUMSUM** — Enjoy Sum with Operations](https://www.spoj.com/problems/SUMSUM/) | Bitmask Segtree | Cada bit é independente + Combinatória básica. | [Local](../../SPOJ/SUMSUM.cpp) |

#### 4️⃣ Segment Tree Beats

| # | Problema | Tópico Principal | 💡 Dica / Ponto de Atenção | Solução |
| :---: | :--- | :--- | :--- | :---: |
| **K** | [**CF 438D** — The Child and Sequence](https://codeforces.com/problemset/problem/438/D) | Segment Tree Beats | Operação de mod em range + set pontual; break quando `mx < mod`. | [Online](https://codeforces.com/contest/438/submission/361641853) • [Local](../../Codeforces/Problemset/438D.cpp) |
| **L** | [**Yosupo** — Range Chmin Chmax Add Range Sum](https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum) | Segment Tree Beats | Composição de tags complexa; cuidado com interações entre chmin/chmax. | [Online](https://judge.yosupo.jp/submission/350912) • [Local](../../Yosupo/range_chmin_chmax_add_range_sum.cpp) |

#### 5️⃣ Persistência

| # | Problema | Tópico Principal | 💡 Dica / Ponto de Atenção | Solução |
| :---: | :--- | :--- | :--- | :---: |
| **M** | [**CSES 1737** — Range Queries and Copies](https://cses.fi/problemset/task/1737/) | Persistência | Exige cópia inteligente (compreensão profunda da estrutura). | [Online](https://cses.fi/problemset/result/16159007/) • [Local](../../CSES/1737.cpp) |
| **N** | [**SPOJ MKTHNUM** — K-th Number](https://www.spoj.com/problems/MKTHNUM/) | Persistência | Busca Binária na árvore persistente ($K$-th number em array). | [Local](../../SPOJ/MKTHNUM.cpp) |
| **O** | [**SPOJ COT** — Count on a Tree](https://www.spoj.com/problems/COT/) | PST + LCA | $K$-th em árvore; walk com 4 nós (l, r, lca, parent). Compressão de coords. | [Local](../../SPOJ/COT-compressed.cpp) |