/* 
Kruskal :クラスカル法で minimum spanning tree を求める構造体
union_findも必要
入力: 辺のvector, 頂点数V
最小全域木の重みの総和: sum
計算量: O(|E|log|V|)
vector<Edge> edges;
辺の代入　Edge e={s,t,cost}; edges.pb(e);
Kruskal krs(edges,N);
辺の重みの総和はkrs.sum
MST上でのa,b間距離はkrs.distance(a,b) 
*/
// 辺の定義
struct Edge {
    long long u;
    long long v;
    long long cost;
};

bool comp_e(const Edge &e1, const Edge &e2) {
    return e1.cost < e2.cost;
}

struct Kruskal {
    long long sum;   // 最小全域木の重みの総和
    vector<Edge> edges;
    int V;

    // MSTの隣接リスト
    vector<vector<pair<int,long long>>> g;

    // LCA用
    int LOG;
    vector<vector<int>> parent;
    vector<int> depth;
    vector<long long> dist; // 根からの距離

    Kruskal(const vector<Edge> &edges_, int V_) : edges(edges_), V(V_) {
        Init();
    }

    void Init() {
        sort(edges.begin(), edges.end(), comp_e);

        g.assign(V, {});
        sum = 0;

        init(V); // union_find の初期化

        // MST構築
        for (auto e : edges) {
            if (!same(e.u, e.v)) {
                unite(e.u, e.v);
                sum += e.cost;

                g[e.u].push_back({(int)e.v, e.cost});
                g[e.v].push_back({(int)e.u, e.cost});
            }
        }
        // LOG決定
        LOG = 1;
        while ((1LL << LOG) <= V) LOG++;

        parent.assign(LOG, vector<int>(V, -1));
        depth.assign(V, -1);
        dist.assign(V, 0);

        // 連結グラフなら 0 を根にすればよい
        // 非連結グラフにも対応するため全頂点を見る
        for (int i = 0; i < V; i++) {
            if (depth[i] == -1) dfs(i, -1, 0, 0);
        }

        // ダブリング前計算
        for (int k = 0; k + 1 < LOG; k++) {
            for (int v = 0; v < V; v++) {
                if (parent[k][v] == -1) parent[k + 1][v] = -1;
                else parent[k + 1][v] = parent[k][ parent[k][v] ];
            }
        }
    }
    void dfs(int v, int p, int d, long long c) {
        parent[0][v] = p;
        depth[v] = d;
        dist[v] = c;
        for (auto [to, cost] : g[v]) {
            if (to == p) continue;
            if (depth[to] != -1) continue;
            dfs(to, v, d + 1, c + cost);
        }
    }
    int lca(int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);

        int diff = depth[a] - depth[b];
        for (int k = 0; k < LOG; k++) {
            if (diff & (1 << k)) a = parent[k][a];
        }

        if (a == b) return a;

        for (int k = LOG - 1; k >= 0; k--) {
            if (parent[k][a] != parent[k][b]) {
                a = parent[k][a];
                b = parent[k][b];
            }
        }

        return parent[0][a];
    }
    // 最小全域木上の2頂点間距離
    long long distance(int a, int b) {
        int c = lca(a, b);
        return dist[a] + dist[b] - 2LL * dist[c];
    }
};
