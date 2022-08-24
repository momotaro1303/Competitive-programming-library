//素因数分解(O(sqrt(n))
/*map<ll, ll> prime = prime_fact(M)のように宣言
    for (auto itr : prime) {
        ll n1=itr.first;
        ll n2=itr.second;
    }みたいに参照
*/
map<ll,ll> prime_fact(ll n){
    map<ll,ll> res;
    for(ll i=2;i*i<=n;i++){
        while(n%i==0){
            ++res[i];
            n/=i;
        }
    }
    if(n!=1) res[n]=1;
    return res;
}