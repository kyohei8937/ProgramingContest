#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1LL << 60;

// 便利関数
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,n,m) for(int i=n;i<m;++i)
#define ALL(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

//============================================================================
//ここまでテンプレ
//============================================================================

const int mod = 1000000007;

int K;
int dp[100100];

void solve(){
    dp[0] = 1;

    
    if(K%9!=0){
        cout << 0 << endl;
        return;
    }
    

	rep2(i,1,K+1){
        int B = min(i,(int)9);
        rep2(j,1,B+1){
            dp[i] = (dp[i] + dp[i-j]) % mod;
        }
	}
	cout << dp[K] << endl;
    return;
}

signed main(){
    cin >> K;
    solve();
    return 0;
}