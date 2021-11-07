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

#define MAX 16

int H,W;
int mp[MAX+2][MAX+2];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
bool used[20][20];

int dfs(int sx, int sy, int px, int py){

	if(sx == px && sy == py && used[px][py] == true){
		return 0;
	}
	used[px][py] = true;

	int ret = -10000;
	rep(i,4){
		int nx = px + dx[i] ,ny = py + dy[i];
		// 山なら移動しない
		if(mp[nx][ny] == 0){
			continue;
		}

		// 移動済み
		if((sy != nx || sy != ny) && used[nx][ny] == true) {
			continue;
		}
		int v = dfs(sx,sy,nx,ny);
		ret = max(ret,v+1);
	}
	used[px][py] = false;
    return ret;
}

signed main(){
    cin >> H >> W;
	rep(i,H){
		rep(j,W){
			char tmp;
			cin >> tmp;
			if(tmp == '.'){
				mp[i+1][j+1] = 1;
			}
		}
	}

	int ans = -1;
	rep(i,H){
		rep(j,W){
			ans = max(ans,dfs(i+1,j+1,i+1,j+1));
		}
	}
	if(ans <= 2){
		ans = -1;
	}
	cout << ans << endl;
    return 0;
}