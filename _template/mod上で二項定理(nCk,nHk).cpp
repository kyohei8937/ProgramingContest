#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1LL << 60;
const int MOD = 1000000007;

// マクロ
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,n,m) for(int i=n;i<m;++i)
#define ALL(x) (x).begin(),(x).end()

//#define DEBUG
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
template <typename T> T median(vector<T>& c){size_t n = c.size() / 2;nth_element(c.begin(), c.begin() + n, c.end());return c[n];}
// ...べき乗のmodで割った余り
int modpow(int a, int n, int mod) {int res = 1;while (n > 0) {if (n & 1) res = res * a % mod;a = a * a % mod;n >>= 1;}return res;}
// ...最大公約数
int gcd(int a, int b) {if (b==0) return a;else return gcd(b, a%b);}
// ...最小公倍数
int lcm(int a, int b) {return a * b / gcd(a, b);}

//============================================================================
//ここまでテンプレ
//============================================================================

// https://atcoder.jp/contests/abc132/tasks/abc132_d
// https://drken1215.hatenablog.com/entry/2018/06/08/210000

int N,K;

/*  init_nCk :二項係数のための前処理
    計算量:O(n)
*/
vector<int> fact, fact_inv, inv;
void init_nCk(int SIZE) {
    fact.resize(SIZE + 5);
    fact_inv.resize(SIZE + 5);
    inv.resize(SIZE + 5);
    fact[0] = fact[1] = 1;
    fact_inv[0] = fact_inv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < SIZE + 5; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        fact_inv[i] = fact_inv[i - 1] * inv[i] % MOD;
    }
}
/*  nCk :MODでの二項係数を求める(前処理 init_nCk が必要)
    計算量:O(1)
*/
int nCk(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fact[n] * (fact_inv[k] * fact_inv[n - k] % MOD) % MOD;
}

/*  nHk = (n+k-1)Ck
*/
int nHk(int n, int k) {
    return nCk(n+k-1,k);
}

void solve(){
    init_nCk(510000);

    int B = K;
    int R = N - K;

    rep2(k,1,K+1){
        int r = R-(k-1);
        int b = B-k;

        int combB = nHk(k,b);
        int combR = nHk(k+1,r);

        _printf("%lld %lld\n", combB , combR);

        cout << (combB * combR) % MOD << endl;
    }

    return;
}

signed main(){
    cin >> N >> K;
    solve();
    return 0;
}