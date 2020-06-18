//dijkstra法
/*計算量はO(Vlog(V)) firstが最短距離　secondが頂点の番号　
代入はこうするG[a].pb((edge){b,c});　*/
struct edge{ll to,cost;};
ll V; 
vector<edge> G[MAX_V];
ll d[MAX_V];
void dijkstra(ll s){
    priority_queue<P,vector<P>,greater<P> > que;
    fill(d,d+V,INF);
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
                que.push(P(d[e.to],e.to));
            }
        }
    }
}
