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
int v[3] = {3,5,7};
int ans = 0;

void solve(){

    rep2(dgt,3,10){
        int ma = 1;
        rep(i,dgt) ma*=3;

        rep(msk,ma){
            int  x = 0;
            int m = msk;
            int cn[3] = {0, 0, 0};
            rep(i,dgt) {
                int d = m % 3;
                x = x * 10 + v[d];
                cn[d]++;
                m /= 3;
            }
            if(x <= N && 0 < cn[0]  && 0 < cn[1] && 0 < cn[2]) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return;
}

signed main(){
    cin >> N;
    solve();
    return 0;
}