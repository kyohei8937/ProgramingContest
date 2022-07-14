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
template <typename T> T Median(std::vector<T>& c) { size_t n = c.size() / 2; std::nth_element(c.begin(), c.begin() + n, c.end()); return c[n]; }
// ...べき乗のmodで割った余り
int ModPow(int a, int n, int mod) { int res = 1; while (n > 0) { if (n & 1) res = res * a % mod; a = a * a % mod; n >>= 1; }return res; }
// ...最大公約数
int GCD(int a, int b) { if (b == 0) return a; else return GCD(b, a % b); }
// ...最小公倍数
int LCM(int a, int b) { return a * b / GCD(a, b); }

//============================================================================
//ここまでテンプレ
//============================================================================
int N;
#ifndef RANDOM_CHECK

int sosu_num;
int sosu_syurui;

// 素因数分解
template <typename T>
map<T, T> prime_factor(T n) {
    map<T, T> ret;
    for (T i = 2; i * i <= n; i++) {
        T tmp = 0;
        while (n % i == 0) {
            tmp++;
            n /= i;
        }
        ret[i] = tmp;
    }
    if (n != 1) ret[n] = 1;
    return ret;
}
// 約数の個数を求める
template <typename T>
T divisor_num(T N) {
    map<T, T> pf = prime_factor(N);
    T ret = 1;
    for (auto p : pf) {
        ret *= (p.second + 1);
    }
    return ret;
}
// 平方数かどうかの判定
bool is_squere(long long N) {
    return divisor_num(N) % 2 == 1;
}

vector<pair<long long, long long> > prime_factorize(long long N) {
    sosu_num = 0;
    sosu_syurui = 0;
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({ a, ex });
        sosu_num += ex;
        sosu_syurui++;
    }

    // 最後に残った数について
    if (N != 1) {
        res.push_back({ N, 1 });
        sosu_num++;
        sosu_syurui++;
    }
    return res;
}

void solve() {
    int pairNum[200000] = {0};
    int count_heihou = 0;
    int ans = 0;
    rep2(i, 1, N + 1) {
        sosu_num = 0;
        sosu_syurui = 0;
        // 素因数分解
        const auto& res = prime_factorize(i);
        bool isheihou = true;
        // 素数が1以下なら加算なし
        if (sosu_num  <= 1) {
            continue;
        }
        for (auto p : res) {
            if (p.second % 2 != 0) {
                isheihou = false;
            }
        }
        // これまでの平方根と合体可能
        if (isheihou) {
            count_heihou++;
            ans = ans + count_heihou * 2;
        }
        // 素数が1種類かつ素数の数が奇数・・・その素数と合体可能。合体できる数字も含めて
        else if (sosu_syurui == 1 && sosu_num % 2 != 0) {
            for (auto p : res) {
                ans = ans + 2 + pairNum[p.first]*2;
                pairNum[p.first]++;
            }
        }
        // 素数の数が奇数・・・その素数と合体可能。合体できる数字も含めて
        else{
            int target = 1;
            for (auto p : res) {
                if (p.second % 2 != 0) {
                    target = target * p.first;
                }
            }
            if(target < i) {
                ans = ans + 2 + pairNum[target] * 2;
                pairNum[target]++;
            }
        }
    }

    ans = ans + N;
    cout << ans << endl;
    return;
}

void guchoku()
{
    int count = 0;
    rep2(i, 1, N + 1) {
        rep2(j, 1, N + 1) {
            if (is_squere(i * j)) {
                if (i != j) {
                    _printf("[%d,%d]\n", i, j);
                    count++;
                }
            }
        }
    }
    cout << count << endl;
}

signed main() {
        cin >> N;
        solve();
    return 0;
}
#else // RANDOM_CHECK
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
            return;
        }
    }
    cout << "OK!" << endl;
    return 0;
}
#endif // RANDOM_CHECK