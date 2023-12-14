//組み合わせ列挙
/*
計算量は不明。以下の制約で通るくらいには速い
https://atcoder.jp/contests/cpsco2019-s1/tasks/cpsco2019_s1_c
vector<int> v{1, 2, 3, 4, 5, 6, 7};
do {
    for (int i = 0; i < k; i++) {
        cout << v[i] << " ";
    }
    cout << "| ";
    for(int i = k; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}while(next_combination(all(v),k));
1 2 3 | 4 5 6 7 
1 2 4 | 3 5 6 7 
1 2 5 | 3 4 6 7 
1 2 6 | 3 4 5 7 
1 2 7 | 3 4 5 6 
1 3 4 | 2 5 6 7 
1 3 5 | 2 4 6 7 
1 3 6 | 2 4 5 7 
1 3 7 | 2 4 5 6 
1 4 5 | 2 3 6 7
...
*/
template <typename T> bool next_combination(const T first, const T last, int k) {
    const T subset = first + k;
    // empty container | k = 0 | k == n 
    if (first == last || first == subset || last == subset) {
        return false;
    }
    T src = subset;
    while (first != src) {
        src--;
        if (*src < *(last - 1)) {
            T dest = subset;
            while (*src >= *dest) {
                dest++;
            }
            iter_swap(src, dest);
            rotate(src + 1, dest + 1, last);
            rotate(subset, subset + (last - dest) - 1, last);
            return true;
        }
    }
    // restore
    rotate(first, subset, last);
    return false;
}
