//Fenwick tree
/*1オリジンであることに注意　bit[]の初期化がad関数で*/
ll bit[300005];
ll sum(int i){
  ll ret=0;
  while(i){
    ret^=bit[i];
    i-=(i&-i);
  }
  return ret;
}
void ad(int i,int x){
  while(i<=N){
    bit[i]^=x;
    i+=(i&-i);
  }
}