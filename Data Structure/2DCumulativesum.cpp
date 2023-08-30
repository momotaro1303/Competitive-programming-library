//二次元累積和
/*
前計算O(HW) クエリO(1) 0オリジン
vector<vector<ll>> grid(H,vector<ll>(W,0));
vector<vector<ll>> S;
pre_process(grid,S);
query(h1,h2,w1,w2,S)で呼ぶ
*/
// 前処理を行う
void pre_process(vector<vector<ll>> const &a, vector<vector<ll>> &S) {
    int H = (int)a.size();
    int W = (int)a[0].size();
    S.assign(H + 1, vector<ll>(W + 1));
    for (int h = 1; h < H + 1; h++) {
        for (int w = 1; w < W + 1; w++) {
            S[h][w] = a[h - 1][w - 1] + S[h][w - 1] + S[h - 1][w] - S[h - 1][w - 1];
        }
    }
}
// [h1,h2)×[w1,w2) の区間和を求める
int query(int h1, int h2, int w1, int w2, vector<vector<ll>> const &S) {
    return S[h2][w2] - S[h1][w2] - S[h2][w1] + S[h1][w1];
}
