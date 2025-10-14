// BellmanFord法
/*
O(VE)
負閉路がなければ負辺があっても最短距離が求まる。
*/
ll V,E;
struct Edge{ll from,to,cost;};
const ll MAX_E=5005;
Edge es[MAX_E];
void shortest_path(ll s){
  for(ll i=0;i<V;i++) d[i]=INF;
  d[s]=0;
  while(true){
    bool update=false;
    for(ll i=0;i<E;i++){
      Edge e=es[i];
      if(d[e.from]!=INF&&d[e.to]>d[e.from]+e.cost){
        d[e.to]=d[e.from]+e.cost;
        update=true;
      }
    }
    if(!update) break;
  }
}
//trueなら負の閉路が存在する
bool find_negative_loop(){
  memset(d,0,sizeof(d));
  for(ll i=0;i<V;i++){
    for(ll j=0;j<E;j++){
      Edge e=es[j];
      if(d[e.to]>d[e.from]+e.cost){
        d[e.to]=d[e.from]+e.cost;
        //V回目にも更新があるなら負の閉路が存在する
        if(i==V-1) return true;
      }
    }
  }
  return false;
}