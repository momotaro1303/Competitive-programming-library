//素因数分解
/*
クエリ　(O(rるるるルルルルルルルルルルルルルルルルるるあ))
map<ll, ll> prime = prime_fact(M)のように宣言
for (auto itr : prime) {
  ll n1=itr.first;
  ll n2=itr.second;
}
みたいに参照
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

//SPFを使った素因数分解
/*
前処理O(nloglogn) クエリO(logn)
PrimeFact SPF(N); 1からNまでの各整数nの最小の素因数を求める。
map<ll,ll> PF=SPF.get(n); nを素因数分解する。
*/

template <typename T>
struct PrimeFact {
    vector<T> spf;
    PrimeFact(T N) { init(N); }
    void init(T N) { // 前処理。spf を求める
        spf.assign(N + 1, 0);
        for (T i = 0; i <= N; i++) spf[i] = i;
        for (T i = 2; i * i <= N; i++) {
            if (spf[i] == i) {
                for (T j = i * i; j <= N; j += i) {
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }
    }
    map<T, T> get(T n) { // nの素因数分解を求める
        map<T, T> m;
        while (n != 1) {
            m[spf[n]]++;
            n /= spf[n];
        }
        return m;
    }
};
