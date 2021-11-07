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

#define MAX 100

int H,W;
int A[MAX][MAX];
int B[MAX][MAX];

void solve(){

	int sum = 0;
	rep(i,H-1){
		rep(j,W-1){
			int diff = B[i][j] - A[i][j];
			sum += abs(diff);
			A[i][j] += diff;
			A[i][j+1] += diff;
			A[i+1][j] += diff;
			A[i+1][j+1] += diff;
		}
	}

	rep(i,H){
		rep(j,W){
			if(B[i][j] != A[i][j]){
				cout << "No" << endl;
				return;
			}
		}
	}
	cout << "Yes" << endl;
	cout << sum << endl;
    return;
}

signed main(){
    cin >> H >> W;
	rep(i,H){
		rep(j,W){
			cin >> A[i][j];
		}
	}
	rep(i,H){
		rep(j,W){
			cin >> B[i][j];
		}
	}
    solve();
    return 0;
}