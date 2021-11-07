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

int N,K;

int modpow(int a, int n, int mod) {
    int res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}


void solve(){
	if(N==1){
		cout << K << endl;
	}
	else if(N==2){
		if(K==1){
			cout << 0 << endl;
		}else{
			cout << (K*(K-1))% MOD << endl;
		}
	}
	else if(N>=3 && K <=2 ){
		cout << 0 << endl;
	}else{
		int ans = 0;
		ans = (K*(K-1))% MOD;
		cout << (ans * modpow(K-2, N-2, 1000000007))%MOD << endl;		
	}
}

signed main(){
    cin >> N >> K;
    solve();
    return 0;
}