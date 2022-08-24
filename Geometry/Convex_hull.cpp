//凸包
/*
https://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull/Monotone_chain#C++
計算量はO(nlogn)
vector<Point> PP=convex_hull(P)で生成
*/
typedef ld coord_t;         
typedef ld coord2_t;  
struct Point {
  coord_t x, y;
  bool operator <(const Point &p) const {
    return x < p.x || (x == p.x && y < p.y);
  }
};
coord2_t cross(const Point &O, const Point &A, const Point &B)
{
  return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
vector<Point> convex_hull(vector<Point> P)
{
  size_t n = P.size(), k = 0;
  if (n <= 3) return P;
  vector<Point> H(2*n); 
  sort(P.begin(), P.end());
  for (size_t i = 0; i < n; ++i) {
    while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
    H[k++] = P[i];
  }
  for (size_t i = n-1, t = k+1; i > 0; --i) {
    while (k >= t && cross(H[k-2], H[k-1], P[i-1]) <= 0) k--;
    H[k++] = P[i-1];
  }
  H.resize(k-1);
  return H;
}