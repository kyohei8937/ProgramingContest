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

int N;

typedef vector<vector<int> > Matrix;
Matrix d; // グラフの距離を格納した2次元配列（隣接行列）
          // d[u][v]は辺e=(u,v)のコスト（辺が存在しない場合はINF、ただしd[i][i]=0）

void warshall_floyd(int n) { // nは頂点数
  rep (i,n){      // 経由する頂点
    rep (j,n){    // 開始頂点
      rep (k,n){  // 終端
        d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
      }
    }
  }
}

signed main() {
  int n, m;
  cin >> n;

  d = Matrix(n, vector<int>(n, INF));
  rep (i,n) {
      d[i][i] = 0;
  }
  
  cin >> m;
  rep (i,m) {
    int from, to, cost;
    cin >> from >> to >> cost;
    d[from][to] = cost;
  }
  
  warshall_floyd(n);
  
  rep (i,n) {
    rep (j,n) {
      if (i != j && d[i][j] != INF)
        cout << i << "から" << j << "へのコスト: " << d[i][j] << endl;
    }
  }
  
  return 0;
}