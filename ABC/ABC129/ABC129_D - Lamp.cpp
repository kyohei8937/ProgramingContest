#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1LL << 60;
const int MOD = 1000000007;

// マクロ
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,n,m) for(int i=n;i<m;++i)
#define ALL(x) (x).begin(),(x).end()

//#define DEBUG
#ifdef DEBUG
# define _PRINTF(fmt, ...)  printf(fmt, __VA_ARGS__);                   
#else
# define _PRINTF(fmt, ...)
#endif

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

int H,W;
int S[2002][2002];
int S_H[2002][2002];
int S_W[2002][2002];

map<int,int> disW[2002];
map<int,int> disH[2002];

void solve(){

    memcpy(S_W,S,sizeof(int) * 2002 * 2002);
    memcpy(S_H,S,sizeof(int) * 2002 * 2002);

    int cur = -1;
    rep2(i,1,H+2){
        cur = -1;
        rep2(j,1,W+2){
            // # -> .
            if(S[i][j] == 0){
                if(S[i][j-1] == -1)
                {
                    cur = j;
                }
                S_W[i][j] = cur;
            }
            // . -> #
            if(S[i][j-1] != -1 && S[i][j] == -1){
                int dis = j - cur;
                disW[i][cur] = dis;
                _PRINTF("disW[%lld][%lld] = %lld\n",i, cur ,dis);
            }
        }
    }

    rep2(i,1,W+2){
        int cur = -1;
        rep2(j,1,H+2){
            // # -> .
            if(S[j][i] == 0){
                if(S[j-1][i] == -1)
                {
                    cur = j;
                }
                S_H[j][i] = cur;
            }
            // . -> #
            if(S[j-1][i] != -1 && S[j][i] == -1){
                int dis = j - cur;
                disH[i][cur] = dis;
                _PRINTF("disH[%lld][%lld] = %lld\n",i, cur ,dis);
            }
        }
    }

    rep2(i,1,H+1){
        rep2(j,1,W+1){
             _PRINTF("%02lld ", S_W[i][j]);
        }
        _PRINTF("%s","\n");
    }
    _PRINTF("%s", "-----------------------\n");

    rep2(i,1,H+1){
        rep2(j,1,W+1){
             _PRINTF("%02lld ", S_H[i][j]);
        }
        _PRINTF("%s","\n");
    }
    _PRINTF("%s", "-----------------------\n");
           


    int ans = -1;
    rep2(i,1,H+1){
        rep2(j,1,W+1){
            if(S[i][j] != -1){
                int sum = disW[i][S_W[i][j]] + disH[j][S_H[i][j]] - 1;
                S[i][j] = sum;
                _PRINTF("[%lld %lld] - [%lld-%lld]\n", i, j, disW[i][S_W[i][j]], disH[j][S_H[i][j]]);
                chmax(ans,sum);
            }
            //_PRINTF("%02lld ", S[i][j]);
        }
        _PRINTF("%s","\n");
    }
    cout << ans << endl;
    return;
}

signed main(){
    cin >> H >> W;

    rep(i,W+2){
        S[0][i] = -1;
        S[H+1][i] = -1;
    }
    rep(i,H+2){
        S[i][0] = -1;
        S[i][W+1] = -1;
    }

    rep(i,H){
        rep(j,W){
            char c;
            cin >> c;
            if(c=='#'){
                S[i+1][j+1] = -1;
            }else{
                S[i+1][j+1] = 0;
            }
        }
    }

    rep(i,H+2){
        rep(j,W+2){
            _PRINTF("%02lld ",S[i][j]);
        }
        _PRINTF("%s","\n");
    }
    _PRINTF("%s","==================\n");

    solve();
    return 0;
}