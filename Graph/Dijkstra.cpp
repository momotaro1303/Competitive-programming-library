//dijkstra法
/*計算量はO(Vlog(V)) firstが最短距離　secondが頂点の番号　
代入はこうするG[a].pb((edge){b,c});　
頂点tへの経路復元はvector<ll> v=get_path(t);
*/
struct edge{ll to,cost;};
ll V; 
vector<edge> G[MAX_V];
ll d[MAX_V];
ll pre[MAX_V];
void dijkstra(ll s){
    priority_queue<P,vector<P>,greater<P> > que;
    fill(d,d+N,INF);
    fill(pre,pre+N,-1);
    d[s]=0;
    que.push(P(0,s));
    while(!que.empty()){
        P p=que.top(); que.pop();
        ll v=p.second;
        if(d[v]<p.first) continue;
        for(ll i=0; i<G[v].size(); i++){
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost){
                d[e.to]=d[v]+e.cost;
                pre[e.to]=v;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}
vector<ll> get_path(ll t){
    vector<ll> path;
    for(;t!=-1;t=pre[t]) path.pb(t);
    reverse(path.begin(),path.end());
    return path;
}