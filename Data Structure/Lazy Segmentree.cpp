// 遅延評価セグメント木
/*
    区間最小値・最大値を管理
    set(i,x)          : i番目をxにセット（build前）
    build()           : セグ木構築
    Add(a,b,x)        : [a,b) に x を加算
    update(a,b,x)     : [a,b) をすべて x に変更
    query_min(a,b)    : [a,b) の最小値
    query_max(a,b)    : [a,b) の最大値
    find_rightest(a,b,x):
        [a,b) で x以下の要素を持つ最右位置
    find_leftest(a,b,x):
        [a,b) で x以下の要素を持つ最左位置
    使用例：
    RMQ<ll> rmq(N);
    rep(i,N) rmq.set(i,A[i]);
    rmq.build();
    cout << rmq.query_min(l,r) << endl;
    cout << rmq.query_max(l,r) << endl;
*/
template <typename T>
struct RMQ {
    const T INF = numeric_limits<T>::max();
    const T NINF = numeric_limits<T>::lowest();

    int n;

    vector<T> dat_min;
    vector<T> dat_max;

    // 区間加算
    vector<T> lazy_add;

    // 区間代入
    vector<T> lazy_set;
    vector<bool> has_set;


    RMQ(int n_)
        : n(),
          dat_min(n_ * 4, INF),
          dat_max(n_ * 4, NINF),
          lazy_add(n_ * 4, 0),
          lazy_set(n_ * 4, 0),
          has_set(n_ * 4, false)
    {
        int x = 1;
        while (x < n_) x *= 2;
        n = x;
    }


    // build前に使用
    void set(int i, T x) {
        dat_min[i + n - 1] = x;
        dat_max[i + n - 1] = x;
    }


    void build() {
        for (int k = n - 2; k >= 0; k--) {
            dat_min[k] = min(dat_min[2 * k + 1], dat_min[2 * k + 2]);
            dat_max[k] = max(dat_max[2 * k + 1], dat_max[2 * k + 2]);
        }
    }


    // ノードkを値xで全て上書き
    void apply_set(int k, T x) {
        dat_min[k] = x;
        dat_max[k] = x;

        lazy_set[k] = x;
        has_set[k] = true;

        // それ以前の加算情報は消える
        lazy_add[k] = 0;
    }


    // ノードkにxを加算
    void apply_add(int k, T x) {
        dat_min[k] += x;
        dat_max[k] += x;

        if (has_set[k]) {
            lazy_set[k] += x;
        } else {
            lazy_add[k] += x;
        }
    }


    // 遅延情報を子に伝播
    void eval(int k) {
        if (k >= n - 1) return;  // 葉

        int lc = 2 * k + 1;
        int rc = 2 * k + 2;

        // 代入を先に伝える
        if (has_set[k]) {
            apply_set(lc, lazy_set[k]);
            apply_set(rc, lazy_set[k]);

            has_set[k] = false;
        }

        // 加算を伝える
        if (lazy_add[k] != 0) {
            apply_add(lc, lazy_add[k]);
            apply_add(rc, lazy_add[k]);

            lazy_add[k] = 0;
        }
    }


    // --------------------
    // 区間加算
    // --------------------

    void Add(int a, int b, T x, int k, int l, int r) {
        if (r <= a || b <= l) return;

        if (a <= l && r <= b) {
            apply_add(k, x);
            return;
        }

        eval(k);

        int mid = (l + r) / 2;

        Add(a, b, x, 2 * k + 1, l, mid);
        Add(a, b, x, 2 * k + 2, mid, r);

        dat_min[k] = min(dat_min[2 * k + 1],
                         dat_min[2 * k + 2]);

        dat_max[k] = max(dat_max[2 * k + 1],
                         dat_max[2 * k + 2]);
    }


    void Add(int a, int b, T x) {
        Add(a, b, x, 0, 0, n);
    }


    // --------------------
    // 区間代入
    // --------------------

    void update(int a, int b, T x, int k, int l, int r) {
        if (r <= a || b <= l) return;

        if (a <= l && r <= b) {
            apply_set(k, x);
            return;
        }

        eval(k);

        int mid = (l + r) / 2;

        update(a, b, x, 2 * k + 1, l, mid);
        update(a, b, x, 2 * k + 2, mid, r);

        dat_min[k] = min(dat_min[2 * k + 1],
                         dat_min[2 * k + 2]);

        dat_max[k] = max(dat_max[2 * k + 1],
                         dat_max[2 * k + 2]);
    }


    void update(int a, int b, T x) {
        update(a, b, x, 0, 0, n);
    }


    // --------------------
    // 最小値
    // --------------------

    T query_min_sub(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) {
            return INF;
        }

        if (a <= l && r <= b) {
            return dat_min[k];
        }

        eval(k);

        int mid = (l + r) / 2;

        T vl = query_min_sub(a, b, 2 * k + 1, l, mid);
        T vr = query_min_sub(a, b, 2 * k + 2, mid, r);

        return min(vl, vr);
    }


    T query_min(int a, int b) {
        return query_min_sub(a, b, 0, 0, n);
    }


    // --------------------
    // 最大値
    // --------------------

    T query_max_sub(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) {
            return NINF;
        }

        if (a <= l && r <= b) {
            return dat_max[k];
        }

        eval(k);

        int mid = (l + r) / 2;

        T vl = query_max_sub(a, b, 2 * k + 1, l, mid);
        T vr = query_max_sub(a, b, 2 * k + 2, mid, r);

        return max(vl, vr);
    }


    T query_max(int a, int b) {
        return query_max_sub(a, b, 0, 0, n);
    }

    // --------------------
    // x以下の最右位置
    // --------------------

    int find_rightest(int a, int b, T x) {
        return find_rightest_sub(a, b, x, 0, 0, n);
    }


    int find_rightest_sub(int a, int b, T x,
                          int k, int l, int r)
    {
        if (r <= a || b <= l || dat_min[k] > x) {
            return a - 1;
        }

        if (k >= n - 1) {
            return k - (n - 1);
        }

        eval(k);

        int mid = (l + r) / 2;

        // 右側から探す
        int vr = find_rightest_sub(
            a, b, x,
            2 * k + 2,
            mid, r
        );

        if (vr != a - 1) return vr;

        return find_rightest_sub(
            a, b, x,
            2 * k + 1,
            l, mid
        );
    }


    // --------------------
    // x以下の最左位置
    // --------------------

    int find_leftest(int a, int b, T x) {
        return find_leftest_sub(a, b, x, 0, 0, n);
    }


    int find_leftest_sub(int a, int b, T x,
                         int k, int l, int r)
    {
        if (r <= a || b <= l || dat_min[k] > x) {
            return b;
        }

        if (k >= n - 1) {
            return k - (n - 1);
        }

        eval(k);

        int mid = (l + r) / 2;

        // 左側から探す
        int vl = find_leftest_sub(
            a, b, x,
            2 * k + 1,
            l, mid
        );

        if (vl != b) return vl;

        return find_leftest_sub(
            a, b, x,
            2 * k + 2,
            mid, r
        );
    }


    // --------------------
    // debug
    // --------------------

    T operator[](int a) {
        return query_min(a, a + 1);
    }


    void print() {
        for (int i = 0; i < n; i++) {
            cout << (*this)[i];
            if (i + 1 != n) cout << ",";
        }
        cout << endl;
    }
};
