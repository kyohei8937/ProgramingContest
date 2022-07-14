#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1LL << 60;
const int MOD = 1000000007;

// マクロ
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,n,m) for(int i=n;i<m;++i)
#define ALL(x) (x).begin(),(x).end()

#define DEBUG
#ifdef DEBUG
# define _printf(fmt, ...)  printf(fmt, __VA_ARGS__);                   
#else
# define _printf(fmt, ...)
#endif

// 便利関数
// ...最小値・最大値交換
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
// ...中央値
template <typename T> T median(std::vector<T>& c) { size_t n = c.size() / 2; std::nth_element(c.begin(), c.begin() + n, c.end()); return c[n]; }
// ...べき乗のmodで割った余り
int modpow(int a, int n, int mod) { int res = 1; while (n > 0) { if (n & 1) res = res * a % mod; a = a * a % mod; n >>= 1; }return res; }
// ...最大公約数
int gcd(int a, int b) { if (b == 0) return a; else return gcd(b, a % b); }
// ...最小公倍数
int lcm(int a, int b) { return a * b / gcd(a, b); }

//============================================================================
//ここまでテンプレ
//============================================================================

#define MAX 100000

int N, M;
vector<int> A, B;

int useNum[MAX];

class UnionFind {
public:
    vector <int> par; // 各元の親を表す配列
    vector <int> siz; // 素集合のサイズを表す配列(1 で初期化)

    // Constructor
    UnionFind(int sz_) : par(sz_), siz(sz_, 1) {
        for (int i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }
    void init(int sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1);
        for (int i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身ssss
    }

    // Member Function
    // Find
    int root(int x) { // 根の検索
        while (par[x] != x) {
            x = par[x] = par[par[x]]; // x の親の親を x の親とする
        }
        return x;
    }

    // Union(Unite, Merge)
    bool merge(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        // merge technique（データ構造をマージするテク．小を大にくっつける）
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }

    bool issame(int x, int y) { // 連結判定
        return root(x) == root(y);
    }

    int size(int x) { // 素集合のサイズ
        return siz[root(x)];
    }
};


void solve() {
    if (M == 0 || M == 1) {
        cout << "Yes" << endl;
        return;
    }
    UnionFind myUnionFind(N);


    rep(i, M) {
        if (useNum[A[i]] >= 2 || useNum[B[i]] >= 2) {
            cout << "No" << endl;
            return;
        }
        if (myUnionFind.size(A[i]) > 1 && myUnionFind.size(B[i]) > 1) {
            if (myUnionFind.issame(A[i], B[i])) {
                cout << "No" << endl;
                return;
            }
        }
        useNum[A[i]]++;
        useNum[B[i]]++;
        myUnionFind.merge(A[i], B[i]);
    }
    // 隣確定が1以下の人の数
    int lowHuman = 0;
    rep(i, N) {
        if (useNum[i] <= 1) {
            lowHuman++;
        }
    }
    if (lowHuman >= 2) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return;
}

signed main() {
    cin >> N >> M;
    A.resize(M);
    B.resize(M);
    rep(i, M) {
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
    }
    solve();
    return 0;
}