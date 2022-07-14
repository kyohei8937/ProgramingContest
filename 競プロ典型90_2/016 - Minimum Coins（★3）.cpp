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

// ランダムチェック用
void random_checker();

//============================================================================
//ここまでテンプレ
//============================================================================

int N;
vector<int> ABC;

void solve() {
    sort(ALL(ABC));

    int c_max = N / ABC[2];
    int ans = INF;
    for (int i = c_max; i >= 0; i--) {
        int c_amari = N - ABC[2] * i;
        if (c_amari == 0) {
            //cout << i << endl;
            if(i < ans) ans = i;
            break;
        }
        int b_max = c_amari / ABC[1];
        for (int j = b_max; j >= 0; j--) {
            int b_amari = c_amari - ABC[1] * j;
            if (b_amari == 0) {
                if(i+j < ans) ans = i+j;
                break;
            }
            if (b_amari % ABC[0] == 0) {
                int k = b_amari / ABC[0];
                if(i+j+k < ans) ans = i+j+k;
                break;
            }
        }
    }
    cout << ans << endl;
    return;
}

signed main() {
#ifndef RANDOM_CHECK
    cin >> N;
    ABC.resize(3);
    rep(i, 3) {
        cin >> ABC[i];
    }
    solve();

#else
    random_checker();
#endif

    return 0;
}

//============================================================================
//ここからランダムチェッカー用
//============================================================================
int solve_fast() {
    return 0;
}
// ここに愚直法を書く
int solve_Jury() {
    return 0;
}

void random_generate() {
    // ここでランダム生成をする。例えば次のような感じ。
    // for (int i = 0; i < N; i++) A[i] = rand() % 10 + 1;
    // for (int i = 0; i < N; i++) B[i] = rand() % 10 + 1;
}
void random_checker() {
    srand((unsigned int)time(NULL));
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
    return;
}