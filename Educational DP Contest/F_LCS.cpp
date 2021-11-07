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

string s,t;

// dp[i+1][j+1]:sのi文字目とtのj文字目までのLCSの長さ
int dp[3010][3010];

void solve(){

    // LCSを求める
    rep(i,s.length()){
        rep(j,t.length()){
            if(s[i] == t[j]){
                dp[i+1][j+1] = dp[i][j]+1;
            }
            chmax(dp[i+1][j+1],dp[i+1][j]);
            chmax(dp[i+1][j+1],dp[i][j+1]);
        }
    }
    //cout << dp[s.length()][t.length()] << endl;

    // 復元
    string res = "";
    int i = (int)s.size(), j = (int)t.size();
    while(i > 0 && j > 0)
    {
        // (i-1, j) -> (i, j) と更新されていた場合
        if (dp[i][j] == dp[i-1][j]) {
            --i; // DP の遷移を遡る
        }

        // (i, j-1) -> (i, j) と更新されていた場合
        else if (dp[i][j] == dp[i][j-1]) {
            --j; // DP の遷移を遡る
        }

        // (i-1, j-1) -> (i, j) と更新されていた場合
        else {
            res = s[i-1] + res; // このとき s[i-1] == t[j-1] なので、t[j-1] + res でも OK
            --i, --j; // DP の遷移を遡る
        }        
    }

    cout << res << endl;
    return;
}

signed main(){
    cin >> s >> t;
    solve();
    return 0;
}