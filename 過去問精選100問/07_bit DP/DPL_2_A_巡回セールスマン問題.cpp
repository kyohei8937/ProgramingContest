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
// https://algo-logic.info/bit-dp/

#define V_MAX 15

int V,E;
int G[V_MAX+10][V_MAX+10];
 
// dp[S][v] := {0,1,2,…,n-1} の部分集合 S を巡回する |S|! 通りの経路のうち最短のものの距離。ただし、最後に頂点 v に到達した時のみを考える。
int dp[(1<<V_MAX)+1000][V_MAX+10];

void bidDP(){

    // 初期化
    rep(i,1<<V){
        rep(j,V){dp[i][j] = INF; }
    }
    dp[0][0] = 0; 

    // 配るDP
    rep(S, 1 << V) {
        rep(v, V) {
            rep(u, V) {
                if (S != 0 && !(S & (1 << u))) {
                    continue; // u を含まない場合を除く
                }
                if ((S & (1 << v)) == 0) {
                    if (v != u) {
                        chmin(dp[S | (1 << v)][v], dp[S][u] + G[u][v]);
                    }
                }
            }
        }
    }

    if (dp[(1 << V) - 1][0] != INF) {
        cout << dp[(1 << V) - 1][0] << endl;
    } else {
        cout << -1 << endl;
    }   
    return;
}

signed main(){
    cin >> V >> E;

    // 初期化
    rep(i,V){
        rep(j,V){G[i][j] = INF;}
    }

    rep(i,E){
        int s,t,d;
        cin >> s >> t >> d;
        G[s][t] = d;      
    }
    bidDP();
    return 0;
}