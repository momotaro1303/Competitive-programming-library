//warshall_floyd
/*初期化を忘れずに
for(ll i=0; i<N; i++)
for(ll j=0; j<N; j++){
    if(i==j) continue;
    d[i][j]=mod;
}*/
ll d[2505][2505];
void warshall_floyd(ll N){
    for(ll k=0; k<N; k++)
    for(ll i=0; i<N; i++)
    for(ll j=0; j<N; j++) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}