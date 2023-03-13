//行列累乗
/*
フィボナッチ数列での例
mat m(2, vector<ll>(2));
m[0][0] = m[0][1] = m[1][0] = 1;　m[1][1] = 0;
行列mをn乗する
m = mat_pow(m, n);
*/
#define mat vector<vector<ll>>
// 行列積
mat mat_mul(mat &a, mat &b) {
  mat res(a.size(), vector<ll>(b[0].size()));
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < b[0].size(); j++) {
      for (int k = 0; k < b.size(); k++) {
        (res[i][j] += a[i][k] * b[k][j]) %= mod;
      }
    }
  }
  return res;
}
/// 行列累乗
mat mat_pow(mat a, long long n) {
  mat res(a.size(), vector<ll>(a.size()));
  // 単位行列で初期化
  for (int i = 0; i < a.size(); i++)
    res[i][i] = 1;
  // 繰り返し二乗法
  while (n > 0) {
    if (n & 1) res = mat_mul(a, res);
    a = mat_mul(a, a);
    n >>= 1;
  }
  return res;
}
