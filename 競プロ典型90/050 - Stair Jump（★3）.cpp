#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1LL << 60;
const int MOD = 1000000007;

// 便利関数
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,n,m) for(int i=n;i<m;++i)
#define ALL(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

//============================================================================
//ここまでテンプレ
//============================================================================

#define N_MAX 100000
#define L_MAX 100000

int N,L;

// dp[i]:i段あがる組み合わせ
int dp[N_MAX+L_MAX+10];

void solve(){

    dp[0] = 1;
    rep(i,N+1){
        dp[i+1] += dp[i];
        dp[i+L] += dp[i];
        dp[i+1] %= MOD;
        dp[i+L] %= MOD;
    }
    cout << dp[N] % MOD << endl;
}

signed main(){
    cin >> N >> L;
    solve();
    return 0;
}