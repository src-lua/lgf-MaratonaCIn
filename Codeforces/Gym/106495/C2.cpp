#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 4e5+5;

int n, m, q;
vector<pair<int, ll>> adj[MAXN];

int vis[MAXN];
int par[MAXN];
int dep[MAXN];            // Profundidade na DFS
ll depth_weight[MAXN];    // Soma algébrica dos pesos das arestas da árvore até a raiz
ll edge_w[MAXN];          // Peso da aresta que liga ao pai

// Estruturas dos Ciclos
int cycle_count = 0;
int chead[MAXN];          // Head (vértice mais alto) do ciclo
ll cycle_sz[MAXN];        // Soma total dos pesos do ciclo
int cid[MAXN];            // ID do ciclo a qual o nó pertence (0 se for ponte)
ll sum_w[MAXN];           // Distância em arestas de árvore do Head até o nó

// DFS para encontrar todos os ciclos (Back-edges)
void dfs1(int u, int p, int d, ll dw) {
    vis[u] = 1;
    par[u] = p;
    dep[u] = d;
    depth_weight[u] = dw;

    for (auto& edge : adj[u]) {
        int v = edge.first;
        ll w = edge.second;

        if (v == p) continue; // Evita voltar pelo mesmo caminho na árvore

        if (vis[v] == 1) { 
            // Back-edge encontrada -> Achamos um ciclo!
            cycle_count++;
            chead[cycle_count] = v;
            // Peso total do ciclo: Aresta de volta + caminho na árvore
            cycle_sz[cycle_count] = w + depth_weight[u] - depth_weight[v];

            int curr = u;
            // Sobe pela árvore marcando todos os nós que pertencem ao ciclo
            while (curr != v) {
                cid[curr] = cycle_count;
                sum_w[curr] = depth_weight[curr] - depth_weight[v];
                curr = par[curr];
            }
        } else if (vis[v] == 0) {
            edge_w[v] = w;
            dfs1(v, u, d + 1, dw + w);
        }
    }
    vis[u] = 2;
}

// Estruturas da Block-Cut Tree (BCT)
vector<int> bct_adj[MAXN];
ll bridge_w[MAXN];
int bct_up[MAXN][20];
int bct_dep[MAXN];
ll D[MAXN]; // Menor distância da Raiz (1) até o nó

// DFS para processar a BCT (Binary Lifting e Menores Distâncias)
void dfs_bct(int u, int p, int d) {
    bct_up[u][0] = (p == 0 ? 1 : p);
    bct_dep[u] = d;
    for (int i = 1; i < 20; i++) {
        bct_up[u][i] = bct_up[bct_up[u][i-1]][i-1];
    }

    for (int v : bct_adj[u]) {
        if (v <= n) {
            if (u <= n) { 
                // Aresta Ponte normal
                D[v] = D[u] + bridge_w[v];
            } else { 
                // Nó de Ciclo conectando a um vértice original do ciclo
                int c = u - n;
                int H = chead[c];
                ll tree_dist = sum_w[v];
                // A menor distância é por dentro ou por fora do ciclo
                D[v] = D[H] + min(tree_dist, cycle_sz[c] - tree_dist);
            }
        }
        dfs_bct(v, u, d + 1);
    }
}

// Retorna o LCA na Block-Cut Tree
int get_bct_lca(int u, int v) {
    if (bct_dep[u] < bct_dep[v]) swap(u, v);
    for (int i = 19; i >= 0; i--) {
        if (bct_dep[u] - (1 << i) >= bct_dep[v]) u = bct_up[u][i];
    }
    if (u == v) return u;
    for (int i = 19; i >= 0; i--) {
        if (bct_up[u][i] != bct_up[v][i]) {
            u = bct_up[u][i];
            v = bct_up[v][i];
        }
    }
    return bct_up[u][0];
}

// Pega o filho do LCA que está no caminho para 'u'
int get_bct_child(int u, int lca) {
    for (int i = 19; i >= 0; i--) {
        if (bct_dep[u] - (1 << i) > bct_dep[lca]) {
            u = bct_up[u][i];
        }
    }
    return u;
}

// Responde a query em O(log N)
ll query(int u, int v) {
    if (u == v) return 0;
    int lca = get_bct_lca(u, v);

    if (lca <= n) {
        // O LCA é um nó de articulação, caminho simples
        return D[u] + D[v] - 2LL * D[lca];
    } else {
        // O LCA é um Nó de Ciclo. Precisamos atravessar o anel
        int c = lca - n;
        int X = get_bct_child(u, lca); // Entrada de U no ciclo
        int Y = get_bct_child(v, lca); // Entrada de V no ciclo

        ll tree_dist = 0;
        // Pega a distância mantendo a soma algébrica intacta (para pesos negativos)
        if (dep[X] > dep[Y]) tree_dist = sum_w[X] - sum_w[Y];
        else tree_dist = sum_w[Y] - sum_w[X];

        // Melhor caminho dentro do anel
        ll dist_cycle = min(tree_dist, cycle_sz[c] - tree_dist);
        
        // (Dist de U até X) + (Dist de V até Y) + (Dist dentro do anel)
        return (D[u] - D[X]) + (D[v] - D[Y]) + dist_cycle;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // 1. Processa a DFS na raiz 1
    dfs1(1, 0, 0, 0);

    // 2. Constrói a Block-Cut Tree DIRECIONADA
    for (int c = 1; c <= cycle_count; c++) {
        // O head é pai do Nó de Ciclo
        bct_adj[chead[c]].push_back(n + c);
    }
    for (int u = 2; u <= n; u++) {
        if (cid[u] == 0) {
            // Ponte
            bct_adj[par[u]].push_back(u);
            bridge_w[u] = edge_w[u];
        } else {
            // Nó de Ciclo é pai do vértice original
            bct_adj[n + cid[u]].push_back(u);
        }
    }

    // 3. Processa a BCT para responder queries
    D[1] = 0;
    dfs_bct(1, 0, 0);

    // 4. Responde na velocidade da luz
    while (q--) {
        int u, v; cin >> u >> v;
        cout << query(u, v) << '\n';
    }

    return 0;
}