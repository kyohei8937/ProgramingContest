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
template <typename T> T median(std::vector<T>& c){size_t n = c.size() / 2;std::nth_element(c.begin(), c.begin() + n, c.end());return c[n];}
// ...べき乗のmodで割った余り
int modpow(int a, int n, int mod) {int res = 1;while (n > 0) {if (n & 1) res = res * a % mod;a = a * a % mod;n >>= 1;}return res;}
// ...最大公約数
int gcd(int a, int b) {if (b==0) return a;else return gcd(b, a%b);}
// ...最小公倍数
int lcm(int a, int b) {return a * b / gcd(a, b);}

//============================================================================
//ここまでテンプレ
//============================================================================

int N;
vector<int> A,B;
int sumA;
void solve(){
    int ans = 0;
    rep(i,N){
        if(A[i] > B[i]){
            A[i] -= B[i];
            ans+= A[i];
        }else{
            B[i] = B[i]-A[i];
            A[i] = 0;
            if(A[i+1] > B[i]){
                A[i+1] -= B[i];
            }else{
                A[i+1] = 0;
            }
        }
    }
    ans += A[N];
    cout << sumA - ans << endl;
    return;
}

signed main(){
#ifndef RANDOM_CHECK
    cin >> N;
    A.resize(N+1);
    B.resize(N);
    rep(i,N+1){
        cin >> A[i];
        sumA+=A[i];
    }
    rep(i,N){
        cin >> B[i];
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
void random_checker() {
    srand((unsigned int) time(NULL));
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