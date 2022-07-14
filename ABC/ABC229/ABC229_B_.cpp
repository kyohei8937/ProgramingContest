#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1LL << 60;
const int MOD = 1000000007;

// マクロ
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,n,m) for(int i=n;i<m;++i)
#define ALL(x) (x).begin(),(x).end()

#define DEBUG
#ifdef DEBUG
# define DEBUG_PUTS(str) puts(str)
# define DEBUG_PRINTF(fmt, ...)  printf(fmt, __VA_ARGS__);                   
#else
# define DEBUG_PUTS(str)
# define DEBUG_PRINTF(fmt, ...)
#endif

// 便利関数
// ...最小値・最大値交換
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
// ...中央値
template <typename T> T median(std::vector<T>& c){size_t n = c.size() / 2;std::nth_element(c.begin(), c.begin() + n, c.end());return c[n];}
// ...べき乗のmodで割った余り
int modpow(int a, int n, int mod) {int res = 1;while (n > 0) {if (n & 1) res = res * a % mod;a = a * a % mod;n >>= 1;}return res;}

//============================================================================
//ここまでテンプレ
//============================================================================

string A,B;

void solve(){
    return;
}

signed main(){
    cin >> A >> B;
    int mn = min(A.size(),B.size());

    string A_rev (A.rbegin(), A.rend());
    string B_rev (B.rbegin(), B.rend());

    rep(i,mn){
        int a = A_rev[i] - '0';
        int b = B_rev[i] - '0';
        if(a+b >= 10){
            cout << "Hard" << endl;
            return 0;
        }
    }
    cout << "Easy" << endl;
    return 0;
}