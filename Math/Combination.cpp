//コンビネーション
/*
MAXの初期化はconstつける
*/
ll fac[MAX], finv[MAX], inv[MAX];
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - inv[mod%i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}
ll COM(ll n,ll k){
    if (n<k) return 0;
    if (n<0||k<0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}