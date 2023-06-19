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
*/
// 辺の定義
struct Edge {
    long long u;
    long long v;
    long long cost;
};
bool comp_e(const Edge &e1, const Edge &e2) { return e1.cost < e2.cost; } // 辺を直接比較するための関数
struct Kruskal {
    long long sum;  // 最小全域木の重みの総和
    vector<Edge> edges;
    int V;
    Kruskal(const vector<Edge> &edges_, int V_) : edges(edges_), V(V_) {Init();}
    void Init() {
        sort(edges.begin(), edges.end(), comp_e); // 辺の重みでソート
        init(V);
        sum = 0;
        for (auto e : edges) {
            if (!same(e.u, e.v)) { // 閉路にならなければ加える
                unite(e.u, e.v);
                sum += e.cost;
            }
        }
    }
};
