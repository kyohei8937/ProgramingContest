#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1LL << 60;
const int MOD = 10000000000000000;

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
template <typename T> T Median(std::vector<T>& c) { size_t n = c.size() / 2; std::nth_element(c.begin(), c.begin() + n, c.end()); return c[n]; }
// ...べき乗のmodで割った余り
//int ModPow(int a, int n, int mod) { int res = 1; while (n > 0) { if (n & 1) res = res * a % mod; a = a * a % mod; n >>= 1; }return res; }
int ModPow(int a, int n, int mod) {
    int res = 1;
    rep(i, n) {
        res = res * a;
    }
    return res;
}
// ...最大公約数
int GCD(int a, int b) { if (b == 0) return a; else return GCD(b, a % b); }
// ...最小公倍数
int LCM(int a, int b) { return a * b / GCD(a, b); }

//============================================================================
//ここまでテンプレ
//============================================================================
int N, K;
int GetDigit(int num) {
    int digit = 0;
    while (num != 0) {
        num /= 10;
        digit++;
    }
    return digit;
}

#ifndef RANDOM_CHECK
int solve_fast() {
    int K1, K2;
    string K_str;
    K_str = to_string(K);
    K1 = atoll(K_str.c_str());
    reverse(K_str.begin(), K_str.end());
    K2 = atoll(K_str.c_str());
    int ketaK = GetDigit(K1);
    int ketaN = GetDigit(N);

    if (ketaK > ketaN) {
        return 0;
    }
    int ans = 0;
    int ketaDiff = ketaN - ketaK;
     {
        int plus = 2;
        if (K1 == K2) plus = 1;

        ans = plus + (ketaDiff - 1) * plus;
        if (K1 == K2) {
            K1 = K1 * ModPow(10, ketaDiff, MOD);
            if (K1 <= N) ans++;
        }
        else {
            K1 = K1 * ModPow(10, ketaDiff, MOD);
            K2 = K2 * ModPow(10, ketaDiff, MOD);
            if (K1 <= N) ans++;
            if (K2 <= N) ans++;
        }
    }
    return ans;
}
signed main() {
    cin >> N >> K;
    cout << solve_fast() << endl;
    return 0;
}
#else // RANDOM_CHECK
//============================================================================
//ここからランダムチェッカー用
//============================================================================
int solve_fast() {
    int K1, K2;
    string K_str;
    K_str = to_string(K);
    K1 = atoll(K_str.c_str());
    reverse(K_str.begin(), K_str.end());
    K2 = atoll(K_str.c_str());
    int ketaK = GetDigit(K1);
    int ketaN = GetDigit(N);

    if (ketaK > ketaN) {
        return 0;
    }
    int ans = 0;
    int ketaDiff = ketaN - ketaK;
    {
        int plus = 2;
        if (K1 == K2) plus = 1;

        ans = plus + (ketaDiff - 1) * plus;
        if (K1 == K2) {
            K1 = K1 * ModPow(10, ketaDiff, MOD);
            if (K1 <= N) ans++;
        }
        else {
            K1 = K1 * ModPow(10, ketaDiff, MOD);
            K2 = K2 * ModPow(10, ketaDiff, MOD);
            if (K1 <= N) ans++;
            if (K2 <= N) ans++;
        }
    }
    return ans;
}
// ここに愚直法を書く
int solve_Jury() {
    int ans = 0;
    rep2(i,1, N+1) {
        string K_str = to_string(K);
        int K1 = atoll(K_str.c_str());
        reverse(K_str.begin(), K_str.end());
        int K2 = atoll(K_str.c_str());
        string N_str = to_string(i);
        while (N_str.back() == '0') {
            N_str.pop_back();
        }
        int aftN = atoll(N_str.c_str());
        if (aftN == K1 || aftN == K2) {
            ans++;
        }
    }
    return ans;
}

void random_generate() {
    // ここでランダム生成をする。例えば次のような感じ。
    // for (int i = 0; i < N; i++) A[i] = rand() % 10 + 1;
    // for (int i = 0; i < N; i++) B[i] = rand() % 10 + 1;
    N = rand() % 1000+1;
    K = rand() % 1000+1;
    string K_str = to_string(K);
    while (K_str.back() == '0') {
        K_str.pop_back();
    }
    K = atoll(K_str.c_str());
}
signed main() {
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
            //cout << N << " " << K << endl;
            return 0;
        }
    }
    //cout << "OK!" << endl;
    return 0;
}
#endif // RANDOM_CHECK