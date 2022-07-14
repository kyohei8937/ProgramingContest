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

int N, A, B;
int P, Q, R, S;

void solve(){

    int sousa1_1 = max(1-A,1-B);
    int sousa1_2 = min(N-A,N-B);
    int sousa2_1 = max(1-A,B-N);
    int sousa2_2 = min(N-A,B-1);

    _PRINTF("%lld %lld %lld %lld\n", sousa1_1,sousa1_2, sousa2_1, sousa2_2);

    int sousa1_i_first = A+sousa1_1;
    int sousa1_i_last = A+sousa1_2;
    int sousa1_j_first = B+sousa1_1;
    int sousa1_j_last = B+sousa1_2;

    int sousa2_i_first = A+sousa2_1;
    int sousa2_i_last = A+sousa2_2;
    int sousa2_j_first = B-sousa2_1;
    int sousa2_j_last = B-sousa2_2;

    _PRINTF("sousa1_i_first:%lld\n", sousa1_i_first);
    _PRINTF("sousa1_i_last:%lld\n", sousa1_i_last);
    _PRINTF("sousa1_j_first:%lld\n", sousa1_j_first);
    _PRINTF("sousa1_j_last:%lld\n", sousa1_j_last);
    _PRINTF("sousa2_i_first:%lld\n", sousa2_i_first);
    _PRINTF("sousa2_i_last:%lld\n", sousa2_i_last);
    _PRINTF("sousa2_j_first:%lld\n", sousa2_j_first);
    _PRINTF("sousa2_j_last:%lld\n", sousa2_j_last);

    int i_count = 0;

    int diff1 = B-A;

    rep2(i,P,Q+1){
        i_count++;
        int j_count = 0;
        rep2(j,R,S+1){
            char c = '.';
            if(i >= sousa1_i_first && i <= sousa1_i_last){
                if(j == (i + diff1)){
                    c = '#';
                }
            }
            if(i >= sousa2_i_first && i <= sousa2_i_last){
                int tmp = i - sousa2_i_first;
                int tmp2 = sousa2_j_first - tmp;
                if(j == tmp2){
                    c = '#';
                }
            }
            /*
            if(i >= sousa2_i_first && i <= sousa2_i_last){
                if(j >= sousa2_j_last-i_count && j <= sousa2_j_first){
                    c = '#';
                }
            }
            */
            cout << c;
        }
        j_count++;
        cout << endl;
    }
    return;
}

signed main(){
    cin >> N >> A >> B;
    cin >> P >> Q >> R >> S;
    solve();
    return 0;
}