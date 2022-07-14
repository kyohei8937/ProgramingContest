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

//============================================================================
//ここまでテンプレ
//============================================================================

int N, M;
vector<vector<int>> g1, g2;

void solve() {
    vector<int> N_array;
    rep(i, N) {
        N_array.push_back(i);
    }

    bool isOK = true;
    do {
        isOK = true;
        rep(i, N) {
            if(g1[i].size() != g2[N_array[i]].size()){
                isOK = false;
                break;
            }
            if(g1[i].size() == 0){
                continue;
            }
            rep(j, g1[i].size()) {
                bool isHit = false;
                rep(k, g2[N_array[i]].size()) {
                    if (g1[i][j] == N_array[g2[N_array[i]][k]]) {
                        isHit = true;
                        break;
                    }
                }
                if (!isHit) {
                    isOK = false;
                    break;
                }
            }
            if (!isOK) {
                break;
            }
        }
        if (isOK) {
            break;
        }
    } while (next_permutation(N_array.begin(), N_array.end()));
    if (isOK) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return;
}

signed main() {
#ifndef RANDOM_CHECK
    cin >> N >> M;
    g1.resize(N);
    g2.resize(N);
    rep(i, M) {
        int A, B;
        cin >> A;
        cin >> B;
        A--; B--;
        g1[A].push_back(B);
        g1[B].push_back(A);
    }
    rep(i, M) {
        int C, D;
        cin >> C;
        cin >> D;
        C--; D--;
        g2[C].push_back(D);
        g2[D].push_back(C);
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
        N = 8; // 入力データのサイズ（適当に決めて良い）
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