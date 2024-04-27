//セグメント木
/* RMQ：[0,n-1] について、区間ごとの最小値/最大値を管理する構造体
    update(i,x): i 番目の要素を x に更新。O(log(n))
    query(a,b): [a,b) での最小/最大の要素を取得。O(log(n))
    RMQ<ll> rmq(要素数)のように宣言
    rmq.update(i,x)
    rmq.query(a,b)のように使う
*/
template <typename T>
struct RMQ {
    const T INF = numeric_limits<T>::max();
    int n;         // 葉の数
    vector<T> dat; // 完全二分木の配列
    RMQ(int n_) : n(), dat(n_ * 4, INF){ 
        //葉の数は2^xの形 
        //初期値に注意!-INF,0,INFのどれにするか？など
        int x = 1;
        while (n_ > x) {
            x *= 2;
        }
        n = x;
    }

    void update(int i, T x) {
        i += n - 1;
        dat[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;  // parent
            dat[i] = min(dat[i * 2 + 1], dat[i * 2 + 2]);//最大値ならmax
        }
    }

    // the minimum/maximum element of [a,b)
    T query(int a, int b) { return query_sub(a, b, 0, 0, n); }
    T query_sub(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) {
            return INF; //最大値なら-INF
        } else if (a <= l && r <= b) {
            return dat[k];
        } else {
            T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return min(vl, vr);//最大値ならmax
        }
    }
};
