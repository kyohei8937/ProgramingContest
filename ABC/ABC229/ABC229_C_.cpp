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

int N ,W;
int dp[3000000];

int A[3000000];
int B[3000000];

priority_queue<pair<double,int>> umami;

void solve(){
    int ans = 0;
    while(!umami.empty() && W != 0){
        int cur = umami.top().second;
        umami.pop();
        if(W - B[cur] > 0){
            W -= B[cur];
            ans += A[cur] * B[cur];
        }else{
            ans += A[cur] * W;
            W = 0;
        }
        DEBUG_PRINTF("[%lld %lld] ans:%lld W:%lld\n", A[cur], B[cur], ans,W);
    }
    cout << ans << endl;
    return;
}

signed main(){
    cin >> N >> W;
    rep(i,N){
        cin >> A[i] >> B[i];
        double first = A[i];
        int second = i;
        umami.push(make_pair(first,second));
    }
    solve();
    return 0;
}