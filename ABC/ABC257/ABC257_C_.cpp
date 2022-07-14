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
string S;
vector<int> W1,W2;

int dp[2][200100];

#ifndef RANDOM_CHECK
int solve() {
    int ans = 0;
    if (W1.size() == N || W2.size() == N) {
        return N;
    }

    ans = max(W1.size(),W2.size());
    
    rep(i, W1.size()) {
        auto it = lower_bound(ALL(W2), W1[i]);
        if (it != W2.end()) {
            int index = it - W2.begin();
            int otona = W1.size() - i;
            int kodomo = index;
            int newAns = otona + kodomo;
            ans = max(ans, newAns);
        }
        else {
            int otona = W1.size() - i;
            int kodomo = W2.size();
            int newAns = otona + kodomo;
            ans = max(ans, newAns);
        }
    }
    
    rep(i, W2.size()) {
        auto it = lower_bound(ALL(W1), W2[i] + 1);
        if (it != W1.end()) {
            int index = it - W1.begin();
            int kodomo = i;
            int otona = W1.size()-index;
            int newAns = otona + kodomo;
            ans = max(ans, newAns);
        }
        else {
            int otona = 0;
            int kodomo = W2.size()-i;
            int newAns = otona + kodomo;
            ans = max(ans, newAns);
        }
    }

    return ans;
}

signed main() {
    cin >> N >> S;
    rep(i,N){
        int w;
        cin >> w;
        if (S[i] == '1') {
            W1.push_back(w);
        }
        else {
            W2.push_back(w);
        }
    }
    sort(ALL(W1));
    sort(ALL(W2));
    cout << solve() << endl;;
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