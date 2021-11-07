#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1LL << 60;
const int MOD = 1000000007;

// マクロ
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,n,m) for(int i=n;i<m;++i)
#define ALL(x) (x).begin(),(x).end()

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

int N,K;

// https://mayokoex.hatenablog.com/entry/2015/03/23/174029
// dp[n]:駅がnまでであるとした時、nで止まらないという条件のもとで題意の条件を満たす部分集合の数
int dp[1000100];

void solve(){
    dp[0] = 0;
    dp[1] = 1;
    if(K==2){
        dp[2] = 0;
    }else{
        dp[2] = 1;
    }
    if(K==2){
        dp[3] = 1;
    }else{
        dp[3] = 2;
    }
    rep2(i,4,N+1){
        rep2(j,1,K+1){
            if(i-j >= 0){
                dp[i] += dp[i-j] % MOD;
            }
        }
        cout << i << ":" << dp[i] << endl;
    }
    cout << dp[N] << endl;
    return;
}

signed main(){
    cin >> N >> K;
    solve();
    return 0;
}