//セグメント木
/*addは[a,b)にxを加算する sumは[a,b)の和を計算する
add(a,b,x,0,0,N) sum(a,b,0,0,N)のように呼ぶ　
初期化for(ll i=0; i<N; i++) add(i,i+1,A[i],0,0,N); を忘れずに!
どちらもO(logn)
*/
const ll max_n=1<<17;
ll dat1[2*max_n-1],dat2[2*max_n-1];
void add(ll a,ll b,ll x,ll k,ll l,ll r){
    if(a<=l&&r<=b){
        dat1[k]+=x;
    }
    else if(l<b&&a<r){
        dat2[k]+=(min(b,r)-max(a,l))*x;
        add(a,b,x,k*2+1,l,(l+r)/2);
        add(a,b,x,k*2+2,(l+r)/2,r);
    }
}
ll sum(ll a,ll b,ll k,ll l,ll r){
    if(b<=l||r<=a) return 0;
    else if(a<=l&&r<=b) return dat1[k]*(r-l)+dat2[k];
    else{
        ll res=(min(b,r)-max(a,l))*dat1[k];
        res+=sum(a,b,k*2+1,l,(l+r)/2);
        res+=sum(a,b,k*2+2,(l+r)/2,r);
        return res;
    }
}
