#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> PP;
typedef tuple<ll,ll,ll> TTT;
const ll mod=1e9+7,INF=mod*mod*3;
//M_PI 998244353
#define rep(i,N) for(ll i=0; i<(N); i++)
#define rep1(i,N) for(ll i=1; i<(N); i++)
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define si(x) x.size()
#define debug(x,y) cout<<x<<" "<<y<<endl;
#define add(x,y) (x=(x+y)%mod)
#define sub(x,y) (x=(x-y+mod)%mod)
#define mult(x,y) (x=(x*y)%mod)
// 変換
char ltocl(ll x) { return char('a' + x); }// ll -> char (alphabet lower case)
char ltocn(ll x) { return char('0' + x); }// ll -> char (number)
char ltocu(ll x) { return char('A' + x); }// ll -> char (alphabet upper case)
ll cltol(char c) { return ll(c) - ll('a'); }// char (lower case) -> ll
ll cntol(char c) { return ll(c) - ll('0'); }// char (number) -> ll
ll cutol(char c) { return ll(c) - ll('A'); }// char (upper case) -> ll
template<class T> 
inline bool chmax(T &a,const T &b){
  if(a<b) {a=b;return 1;}
  return 0;
}
template<class T> 
inline bool chmin(T &a,const T &b){
  if(b<a) {a=b;return 1;}
  return 0;
}
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    fill( (T*)array, (T*)(array+N), val );
}
// a + b がオーバーフローするならtrueを返す
template <class T> bool overflow_if_add(T a, T b) {
    return (std::numeric_limits<T>::max() - a) < b;
}
// a * b がオーバーフローするならtrueを返す
template <class T> bool overflow_if_mul(T a, T b) {
    return (std::numeric_limits<T>::max() / a) < b;
}
ll mod_inverse(ll a) {
    ll ret=1L;
    ll m=1e9+5L;
    while(m){
      if(m%2){
        ret=(ret*a)%mod;
      }
      m=m/2;
      a=(a*a)%mod;
    }
    return ret;
}
const ll sze=2000005;
ll fc[sze],fv[sze];
ll cb(ll n,ll r){
  ll ret=0;
  ret=fc[n]*fv[n-r]%mod*fv[r]%mod;
  return ret;
}
ll pw(ll x,ll y){
    ll ret=1;
    for(ll i=0; i<y; i++) ret=ret*x;
    return ret;
}
ll ctoi(char c) {
  if(c>='0'&&c<='9'){
    return c-'0';
  }
  return 0;
}
ll gcd(ll a,ll b){
if(a<b) swap(a,b);
if(a%b==0) return b;
else return gcd(a%b,b);
}

#ifdef LOCAL
#define DBG(X,Y) debug(X,Y);
#define SAY(X) cout<<(X)<<endl;
#else
#define DBG(X,Y)
#define SAY(X)
#endif