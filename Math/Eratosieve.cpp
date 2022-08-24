//エラトステネスの篩
/*
計算量はO(nloglogn)程度
ll prime[1000005]はi番目の素数
is_prime[i]がtrueならiが素数
sieve(ll n)はn以下の素数の数を返す
*/
ll prime[1000005]; 
bool is_prime[1000005];　
ll sieve(ll n){
	ll p=0;
	for(ll i=0; i<=n; i++) is_prime[i]=true;
	is_prime[0]=is_prime[1]=false;
	for(ll i=2; i<=n; i++){
		if(is_prime[i]){
			prime[p++]=i;
			for(ll j=2*i; j<=n; j+=i) is_prime[j]=false;
		}
	}
	return p;
}
