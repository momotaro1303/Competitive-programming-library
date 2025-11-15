//BinaryIndexedTree(Fenwick tree)
/*
区間和・一点加算
テンプレのaddをコメントアウトして！
BinaryIndexedTree<ll> bit(N);
bit.add(i,x) O(logN)
bit.range_sum(l,r) O(logN)
*/
template <class T>
class BinaryIndexedTree {
public:
    int n;
    std::vector<T> bit;
    // コンストラクタ
    BinaryIndexedTree(int size) : n(size), bit(size + 1, 0) {}
    // 要素 i (0-indexed) に val を加算する
    void add(int i, T val) {
        // 内部処理用に1-indexedに変換
        i++; 
        while (i <= n) {
            bit[i] += val;
            // 親ノードへ移動
            i += i & -i; 
        }
    }
    // 0 から i (0-indexed) までの要素の和を取得する
    T sum(int i) {
        // 内部処理用に1-indexedに変換
        i++; 
        T s = 0;
        while (i > 0) {
            s += bit[i];
            // 親ノードへ移動
            i -= i & -i; 
        }
        return s;
    }
    // 区間 [l, r) (0-indexed) の和を取得する
    T range_sum(int l, int r) {
        if (l >= r) return 0;
        if (l == 0) return sum(r - 1);
        return sum(r - 1) - sum(l - 1);
    }
};
