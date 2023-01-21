//warshall_floyd
/*初期化を忘れずに
for(ll i=0; i<N; i++){
  for(ll j=0; j<N; j++){
    prv[i][j]=i; 
    if(i==j) continue;
    d[i][j]=INF;
  }
}
経路復元は
int stck[305], sp;
void printPath2(int start, int goal) {
    sp = 0;
    for (int cur = goal; cur != start; cur = prv[start][cur])
        stck[sp++] = cur;
    stck[sp++] = start;
    while (sp--){
      printf("%d%c", stck[sp], " \n"[!sp]);
    }
}
*/
ll d[305][305];
ll prv[305][305];
void warshall_floyd(ll N){
    for(ll k=0; k<N; k++){
      for(ll i=0; i<N; i++){
        for(ll j=0; j<N; j++){
          if(d[i][k]+d[k][j]<d[i][j]){
             d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
             prv[i][j] = prv[k][j];
          }
        }
      }
    }
}
