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
#ifndef RANDOM_CHECK
int N,K;

int solve(){
    int ans = 0;
    if(N == 1) {
        _printf("%d\n", __LINE__);
        ans = K;
    }
    else if(N ==2) {
        _printf("%d\n", __LINE__);
        if(K == 1) {
            ans = 0;
        }else {
            ans = K * (K-1) %MOD;
        }
    }
    else if(K <= 2) {
        _printf("%d\n", __LINE__);
        ans = 0;
    }else {
        _printf("%d\n", __LINE__);
        int a = K * (K-1) % MOD;
        int _modpow = modpow(K-2, N-2, MOD);
        ans = a*_modpow%MOD;
    }
    return ans;
}

signed main(){
    cin >> N >> K;
    cout << solve() << endl;
    return 0;
}
#else // RANDOM_CHECK
int N,K;
//============================================================================
//ここからランダムチェッカー用
//============================================================================
int solve_fast(){
    int ans = 0;
    if(N == 1) {
        _printf("%d\n", __LINE__);
        ans = K;
    }
    else if(N ==2) {
        _printf("%d\n", __LINE__);
        if(K == 1) {
            ans = 0;
        }else {
            ans = K * (K-1) %MOD;
        }
    }
    else if(K <= 2) {
        _printf("%d\n", __LINE__);
        ans = 0;
    }else {
        _printf("%d\n", __LINE__);
        int a = K * (K-1) % MOD;
        int _modpow = modpow(K-2, N-2, MOD);
        ans = a*_modpow%MOD;
    }
    return ans;
}
// ここに愚直法を書く
int solve_Jury(){
    int ans = 1;
    rep(i,N) {
        int keisu;
        if(i==0) {
            keisu = K;
        }
        else if(i==1) {
            keisu = K-1;
        }
        else{
            keisu = K-2;
        }
        ans = ans * keisu % MOD;
    }
    return ans;
}
signed main() {
    srand((unsigned int) time(NULL));
    for (int t = 1; t <= 100000; t++) {
        N = rand() % 100 + 1;
        K = rand() % 100 + 1;
        int J1 = solve_fast();
        int J2 = solve_Jury();
        if (J1 != J2) {
            cout << "Wrong Answer on Test #" << t << endl;
            cout << "Jury = " << J2 << ", Output = " << J1 << endl;
            // テストケースを出力
            printf("N:%d, K:%d\n",N,K);
            return 0;
        }
    }
    cout << "OK!" << endl;
    return 0;
}
#endif // RANDOM_CHECK