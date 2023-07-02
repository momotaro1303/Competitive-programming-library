#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> PP;
typedef tuple<ll,ll,ll> TTT;
const ll mod=998244353,INF=mod*mod*3;
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
#define mult(x,y) (x=((x)*(y))%mod)
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
    for(ll i=0; i<y; i++) mult(ret,x);
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


ライブラリチェッカー
//https://judge.yosupo.jp
標準ライブラリ使い方
//https://qiita.com/gnbrganchan/items/616f3701b1169e834565#multiset
bit演算
//https://qiita.com/drken/items/7c6ff2aa4d8fce1c9361

ll gcd(ll a,ll b){
if(a<b) swap(a,b);
if(a%b==0) return b;
else return gcd(a%b,b);
}
ll lcm(ll a,ll b){
return a/gcd(a,b)*b;
}

map<int,int>::iterator it;
for(it = mp.begin(); it!=mp.end(); it++){
    int n1=it->first;
    int n2=it->second;
    cout<<n2<<endl;
}
for(auto now:mp){
  ll n1=now.first;
  ll n2=now.second;
}


ll cb(ll n,ll r){
  ll ret=0;
  ret=fc[n]*fv[n-r]%mod*fv[r]%mod;
  return ret;
}
fc[0]=1; fv[0]=1;
rep1(i,2*N){ fc[i]=i*fc[i-1]%mod; }
rep1(i,2*N){ fv[i]=mod_inverse(i)*fv[i-1]%mod; }

cout<<fixed<<setprecision(10)<<ans<<endl;
sort(t,t+nt,greater<char>());

stringstream ss;
ss << bitset<8>(9);
string s = ss.str(); //00001001
//下記の方が速いかも
bitset<64> ss(N);
string s=ss.to_string();

struct s {int x; int y;};
bool cmp(const s &a, const s &b){
    return a.x > b.x;
}

char s[100]; int ns=0;
for(int i=0; s[i]!='\0'; ++i) ns++;

//プライオリティキュー
priority_queue<int> q 
priority_queue< int,vector<int>,greater<int> > q;　小さい順

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

lower_bound(a,a+n,k) a>=kとなる最小のインデックス
upper_bound(a,a+n,k) a>kとなる最小のインデックス
//pairをやるとき
upper_bound(all(v), make_pair(u, INF));  //∞
lower_bound(all(v), make_pair(l, -INF)); //マイナス∞

//Xの桁和
ll digit(ll x){
  ll ret=0;
  while(x/10){
    ret+=(x%10);
    x/=10;
  }
  ret+=(x%10);
  return ret;
}

//x^y
ll pw(ll x,ll y){
    ll ret=1;
    for(ll i=0; i<y; i++){
       ret*=x;
    }
    return ret;
}

//文字列の末尾を消去
str.erase(str.end()-1); 

// オーバーフロー 判定
bool over_flow(ll a,ll b){
  ll p=a*b;
  if(p<0){
    return 1;
  }
  else if(p/a==b){
    return 0;
  }else{
    return 1;
  }
}

//素数判定
bool is_prime(ll n){
  if(n==1) return true;
  int cnt=0;
  for(int i=1; i<=sqrt(n); i++){
  if(n%i==0){
    ll a=i;
    ll b=n/i;
    cnt++;
    if(a!=b) cnt++;
  }
  }
  if(cnt==2) return true;
  else return false;
}

//charからintの変換
int ctoi(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  }
  return 0;
}

//vector　nは要素数
vector<ll> v(n);　1次元
vector<vector<ll> > vv(n);　2次元
sort(v.begin(), v.end());
sort(v.begin(), v.end(), greater<ll>());

//nは何桁か
ll keta(ll n){
  ll ret=0;
  ll nn=n;
  while(1){
    nn/=10; 
    ret++;
    if(nn==0) break;
  }
  return ret;
}

//permutation　
//sortされた配列
ll array[]={1,2,3,4};
do{
   for(int i=0; i<4; i++){
        cout<<array[i];
        if(i!=3)cout<<" ";
    }
    cout<<endl;
}while(next_permutation(array,array+4));

//ベクトル(dx,dy)のx軸から反時計回りの角度
long double angle(ll dx,ll dy){
  long double radian=atan2(dy, dx);
  radian=radian*(180.0/M_PI);
  if(radian<0) radian+=360.0;
  return radian;
}

//組み合わせ列挙(0オリジンで)
void recursive_comb(int *indexes, int s, int rest, std::function<void(int *)> f) {
  if (rest == 0) {
    f(indexes);
  } else {
    if (s < 0) return;
    recursive_comb(indexes, s - 1, rest, f);
    indexes[rest - 1] = s;
    recursive_comb(indexes, s - 1, rest - 1, f);
  }
}
void foreach_comb(int n, int k, std::function<void(int *)> f) {
  int indexes[k];
  recursive_comb(indexes, n - 1, k, f);
}
foreach_comb(5,3,[](int *indexes) {
    cout<<indexes[0]<<','<<indexes[1]<<','<<indexes[2]<<endl;
  });

//木を作る
vector<ll> vertex[200005];
vector<ll> DEG[200005];
ll parent[200005];
ll degree[200005];
ll mx_deg;//深さの最大値
bool leaf[200005]; //falseなら葉
void is_leaf(){
  rep1(i,N+1){
    ll n=parent[i];
    if(n!=-1) leaf[n]=true;
  }
  return;
}
void tree(ll par,ll n){
  if(parent[n]!=0) return;
  parent[n]=par;
  for(auto &i:vertex[n]) tree(n,i);
  return;
}
void deg(ll v,ll p_deg){
  degree[v]=p_deg+1;
  chmax(mx_deg,degree[v]);
  if(!leaf[v]) return;
  for(auto &i:vertex[v]){
    if(i!=parent[v]) deg(i,degree[v]);
  }
  return;
}

//巨大な数のmod(100000桁とか)
ll string_mod(string s, ll mod){
    ll rest = 0;
    for(char c : s){
        ll v = c-'0';
        rest = (rest*10 + v) % mod;
    }
    return rest;
}

// 最長増加部分列の長さを求める
/*
vector<ll> a;
LIS(a)みたいにつかう　
*/
int LIS(const vector<long long> &a) {
    int N = (int)a.size();
    vector<long long> dp(N, INF);
    for (int i = 0; i < N; ++i) {
        // dp[k] >= a[i] となる最小のイテレータを見つける
        auto it = lower_bound(dp.begin(), dp.end(), a[i]);
 
        // そこを a[i] で書き換える
        *it = a[i];
    }
 
    // dp[k] < INF となる最大の k に対して k+1 が答え
    // それは dp[k] >= INF となる最小の k に一致する
    return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}
