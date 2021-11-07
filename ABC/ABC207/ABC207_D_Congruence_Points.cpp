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

const int N_MAX = 100;
int N;
int a[N_MAX],b[N_MAX];
int c[N_MAX],d[N_MAX];

void solve(){
	// 2辺を選ぶ
	rep(i,N-1){
		rep2(j,i+1,N){
			rep(k,N-1){
				rep2(l,i+1,N){
					// 距離が違うなら何もしない
					int S_dis = pow((a[i]-a[j]),2)+pow((b[i]-b[j]),2);
					int T_dis = pow((c[k]-a[l]),2)+pow((c[k]-b[l]),2);
					if(S_dis == T_dis){

						// 残りの点



					}
				}
			}
		}
	}
	cout << "No" << endl;
}

signed main() {
	cin >> N;
	rep(i,N){cin >> a[i] >> b[i];}
	rep(i,N){cin >> c[i] >> d[i];}
	solve();
	return 0;
}