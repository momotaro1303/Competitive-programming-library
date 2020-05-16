//LCA
/*parent[k][v]の初期化O(nlogn) クエリ処理O(logn)*/
vector<ll> G[MAX_V];
ll root;
ll parent[MAX_LOG_V][MAX_V];
ll depth[MAX_V];
void dfs(ll v,ll p,ll d){
    parent[0][v]=p;
    depth[v]=d;
    for(ll i=0; i<G[v].size(); i++){
        if(G[v][i]!=p) dfs(G[v][i],v,d+1);
    }
}
void init(ll V){
    dfs(root,-1,0);
    for(ll k=0; k+1<MAX_LOG_V; k++){
        for(ll v=0; v<V; v++){
            if(parent[k][v]<0) parent[k+1][v]=-1;
            else parent[k+1][v]=parent[k][parent[k][v]];
        }
    }
}
ll lca(ll u, ll v){
    if(depth[u]>depth[v]) swap(u,v);
    for(ll k=0; k<MAX_LOG_V; k++){
        if((depth[v]-depth[u])>>k&1){
            v=parent[k][v];
        }
    }
    if(u==v) return u;
    for(ll k=MAX_LOG_V-1; k>=0; k--){
        if(parent[k][u]!=parent[k][v]){
            u=parent[k][u];
            v=parent[k][v];
        }
    }
    return parent[0][u];
}