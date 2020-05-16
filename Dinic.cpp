//Dinic法(最大流を求める)
/*計算量はO(|E||V|^2)*/
struct edge {ll to; ll cap; ll rev;} ;
vector<edge> G[205];
ll level[205];
ll iter[205];
void add_edge(ll from,ll to,ll cap){
    edge e;
    e.to=to, e.cap=cap, e.rev=G[to].size();
    G[from].push_back(e);
    e.to=from, e.cap=0, e.rev=G[from].size()-1;
    G[to].push_back(e);
}
void bfs(ll s){
    memset(level, -1, sizeof(level));
    queue<ll> que;
    level[s]=0;
    que.push(s);
    while(!que.empty()){
        ll v=que.front();
        que.pop();
        for(ll i=0; i<G[v].size(); i++){
            edge e=G[v][i];
            if(e.cap>0 && level[e.to]<0){
                level[e.to]=level[v]+1;
                que.push(e.to);
            }
        }
    }
}
ll dfs(ll v, ll t, ll f){
    if(v==t) return f;
    for(ll &i=iter[v]; i<G[v].size(); i++){
        edge &e=G[v][i];
        if(e.cap>0 && level[v]<level[e.to]){
            ll d=dfs(e.to, t, min(f, e.cap));
            if(d>0){
                e.cap-=d;
                G[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}
ll max_flow(ll s, ll t){
    ll flow=0;
    while(1){
        bfs(s);
        if(level[t]<0) return flow;
        memset(iter, 0, sizeof(iter));
        ll f;
        while((f=dfs(s, t, INF))>0){
            flow+=f;
        }
    }
}