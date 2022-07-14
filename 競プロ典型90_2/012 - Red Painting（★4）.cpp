#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1LL << 60;
const int MOD = 1000000007;

// マクロ
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,n,m) for(int i=n;i<m;++i)
#define ALL(x) (x).begin(),(x).end()

//#define RANDOM_CHECK
#define DEBUG
#ifdef DEBUG
# define _printf(fmt, ...)  printf(fmt, __VA_ARGS__);                   
#else
# define _printf(fmt, ...)
#endif

// 便利関数
// ...最小値・最大値交換
template<class T> inline bool ChMin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool ChMax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
// ...中央値
template <typename T> T Median(std::vector<T>& c){size_t n = c.size() / 2;std::nth_element(c.begin(), c.begin() + n, c.end());return c[n];}
// ...べき乗のmodで割った余り
int ModPow(int a, int n, int mod) {int res = 1;while (n > 0) {if (n & 1) res = res * a % mod;a = a * a % mod;n >>= 1;}return res;}
// ...最大公約数
int GCD(int a, int b) {if (b==0) return a;else return GCD(b, a%b);}
// ...最小公倍数
int LCM(int a, int b) {return a * b / GCD(a, b);}

//============================================================================
//ここまでテンプレ
//============================================================================
#ifndef RANDOM_CHECK
class UnionFind {
public:
    vector <int> par; // 各元の親を表す配列
    vector <int> siz; // 素集合のサイズを表す配列(1 で初期化)

    // Constructor
    UnionFind(int sz_): par(sz_), siz(sz_, 1) {
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

#define MAX 2000
int H,W,Q;
bool isRed[(MAX+2)*(MAX+2)];


signed main(){
    cin >> H >> W >> Q;

    UnionFind myUnionFind((H+2)*(W+2));
    vector<int> ansArray;

    int dir[4] = {-(W+2), 1, (W+2), -1};
    vector<string> ansers;
    rep(i,Q){
        int t;
        cin >> t;
        if(t == 1) {
            int r,c;
            cin >> r >> c;
            int index = r * (W+2) + c;
            isRed[index] = true;
            rep(i,4) {
                int chkIndex = index + dir[i];
                if(chkIndex >= 0 && chkIndex <= (H*2)*(W+2)-1) {
                    if(isRed[chkIndex]) {
                        myUnionFind.merge(index,chkIndex);
                    }
                }
            }
        }
        else {
            int ra,ca,rb,cb;
            cin >> ra >> ca >> rb >> cb;
            int index_a = ra * (W+2) + ca;
            int index_b = rb * (W+2) + cb;
            if(isRed[index_a] && isRed[index_b] && myUnionFind.issame(index_a, index_b)) {
                ansers.push_back("Yes");
            }else {
                ansers.push_back("No");
            }
        }
   }
   rep(i,ansers.size()) {
       cout << ansers[i] << endl;
   }
    return 0;
}
#else // RANDOM_CHECK
//============================================================================
//ここからランダムチェッカー用
//============================================================================
int solve_fast(){
    return 0;
}
// ここに愚直法を書く
int solve_Jury(){
    return 0;
}

void random_generate() {
    // ここでランダム生成をする。例えば次のような感じ。
    // for (int i = 0; i < N; i++) A[i] = rand() % 10 + 1;
    // for (int i = 0; i < N; i++) B[i] = rand() % 10 + 1;
}
signed main() {
    srand((unsigned int) time(NULL));
    for (int t = 1; t <= 1000; t++) {
        //N = 8; // 入力データのサイズ（適当に決めて良い）
        //A.resize(N), B.resize(N); // プログラムで使用する変数
        random_generate();
        int J1 = solve_fast();
        int J2 = solve_Jury();
        if (J1 != J2) {
            cout << "Wrong Answer on Test #" << t << endl;
            cout << "Jury = " << J2 << ", Output = " << J1 << endl;
            // テストケースを出力
            return;
        }
    }
    cout << "OK!" << endl;
    return 0;
}
#endif // RANDOM_CHECK