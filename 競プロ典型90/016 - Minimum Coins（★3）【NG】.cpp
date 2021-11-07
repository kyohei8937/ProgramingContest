#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1LL << 60;

// 便利関数
// ...繰り返し
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,n,m) for(int i=n;i<m;++i)
#define ALL(x) (x).begin(),(x).end()

// ...比較入れ替え
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

//============================================================================
//ここまでテンプレ
//============================================================================

const int N_MAX = 1000000100;
const int ANS_MAX = 10000;

int N;
vector<int> coin;
short dp[N_MAX];

void solve(){
	/*
	for(int i = (N / coin[2]) ; i >= 0; i--){
		for(int j = (N-i*coin[2]) / coin[1]; j >= 0; j--){
			if( (N - (i*coin[2]) - j*coin[1]) % coin[0] == 0){
				int k = (N - (i*coin[2]) - j*coin[1]) / coin[0];
				printf("%lld:%lld, %lld:%lld, %lld:%lld\n",coin[2],i,coin[1],j,coin[0],k);
				cout << i + j + k << endl;
				return;
			}
		}
	}
	*/

	int ans = INF;
	rep(i,ANS_MAX){
		rep(j,ANS_MAX-i){
			if((N - i*coin[2] - j*coin[1]) >= 0 && (N - i*coin[2] - j*coin[1]) % coin[0] == 0){
				int k = (N - i*coin[2] - j*coin[1]) / coin[0];
				//printf("%lld:%lld, %lld:%lld, %lld:%lld\n",coin[2],i,coin[1],j,coin[0],k);
				chmin(ans,i+j+k);
			}
		}
	}
	cout << ans << endl;
}

signed main(){
    cin >> N;
	coin.resize(3);
	cin >> coin[0] >> coin[1] >> coin[2];
	sort(ALL(coin));	
	solve();
    return 0;
}