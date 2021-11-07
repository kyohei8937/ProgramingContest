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

const int mod = pow(10,9)+7;

int N;
string S;

string target = "atcoder";
int dp[7][100100];

void solve(){

	rep(i,7){
		rep2(j,i,N){
			if(S[j] == target[i]){
				if(i==0){
					if(j==0){
						dp[i][j] = 1;
					}else{
						dp[i][j] = dp[i][j-1]+1; 
					}
				}
				else{
					if(dp[i][j-1] == 0){
						dp[i][j] = dp[i-1][j];
					}else{
						dp[i][j] = dp[i][j-1]+dp[i-1][j];
					}				
				}
			}else{
				if(j==0){
					dp[i][j] = 0;
				}else{
					dp[i][j] = dp[i][j-1];
				}
			}
			dp[i][j] = dp[i][j] % mod;
		}
	}
	/*
	rep(i,7){
		rep(j,N){
			printf("%02lld ",dp[i][j]);
		}
		printf("\n");
	}
	*/


	cout << dp[6][N-1] << endl;
}

signed main(){
    cin >> N >> S;
    solve();
    return 0;
}