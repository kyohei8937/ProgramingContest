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
//#define DEBUG
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
int N;
string S;
int dp[7][100100];
#ifndef RANDOM_CHECK
void solve(){
    string str = "atcoder";
    if(S[0] == 'a') {
        dp[0][0] = 1;
    }else {
        dp[0][0] = 0;
    }
    rep(i,7) {
        rep2(j,1,S.size()) {
           if(i == 0) {
                if(S[j] == str[i]) {
                    dp[i][j] = (dp[i][j-1]+1) % MOD;
                }
                else{
                    dp[i][j] = dp[i][j-1];
                }
            }else {
                if(S[j] == str[i]) {
                    dp[i][j] = ((dp[i][j-1]) + dp[i-1][j]) %MOD;
                }
                else{
                    dp[i][j] = dp[i][j-1];
                }                
            }
            _printf("%02lld ", dp[i][j]);
        }
        _printf("%s", "\n");
    }
    cout << dp[6][S.size()-1] << endl;
    return;
}

signed main(){
    cin >> N;
    rep(i,N) {
        char moji;
        cin >> moji;
        if(moji == 'a' || moji == 't' || moji == 'c' || moji == 'o' || moji == 'd' || moji == 'e' || moji == 'r') {
            S.push_back(moji);
        }
    }
    solve();
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