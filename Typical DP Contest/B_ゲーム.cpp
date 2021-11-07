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

// DP[i][j]: 左に i 個、右に j 個残っている状態から始めてお互い最善を尽くしたときの、（先手が得る価値）−（後手が得る価値）

int A,B;
vector<int> a,b;

void solve(){
    return;
}

signed main(){
    cin >> A >> B;
    a.resize(A);
    b.resize(B);
    rep(i,A){
        cin >> a[i];
    }
    rep(i,B){
        cin >> b[i];
    }
    solve();
    return 0;
}