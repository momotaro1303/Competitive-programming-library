//unionfind
/*
initで初期化を忘れずに!
*/
ll siz[100005];
ll par[100005];
ll rnk[100005];
void init(ll n){
	for(ll i=0; i<n; i++){
		par[i]=i;
		rnk[i]=0;
		siz[i]=0;
	}
}
ll find(ll x){
	if(par[x]==x){
		return x;
	}else{
		return par[x]=find(par[x]);
	}
}
void unite(ll x,ll y){
	x=find(x);
	y=find(y);
	if(x==y) return;
	if(rnk[x]<rnk[y]){
		siz[y]+=siz[x];
		par[x]=y;
	}else{
		siz[x]+=siz[y];
		par[y]=x;
		if(rnk[x]==rnk[y]) rnk[x]++;
	}
}
bool same(ll x,ll y){
	return find(x)==find(y);
}
ll size(ll x) {
    return siz[find(x)];
}