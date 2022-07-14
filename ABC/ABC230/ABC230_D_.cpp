#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1LL << 60;
const int MOD = 1000000007;

// マクロ
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,n,m) for(int i=n;i<m;++i)
#define ALL(x) (x).begin(),(x).end()

#define DEBUG
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

int N,D;
vector<pair<int,int>> LRs;

vector<int> panchs; 

void solve(){

    rep(i,N){
        bool isHit = false;
        rep(j,panchs.size()){
            if(panchs[j]+2 >= LRs[i].first && panchs[j] <= LRs[i].second){
                isHit = true;
                break;
            }
        }
        if(!isHit){
            panchs.push_back(LRs[i].second);
        }
    }

    cout << panchs.size() << endl;

    return;
}

signed main(){
    cin >> N >> D;
    LRs.resize(N);
    rep(i,N){
        int L,R;
        cin >> LRs[i].first >> LRs[i].second;
    }
    sort(ALL(LRs));
    solve();
    return 0;
}