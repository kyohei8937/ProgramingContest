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
# define DEBUG_PUTS(str) puts(str)
# define DEBUG_PRINTF(fmt, ...)  printf(fmt, __VA_ARGS__);                   
#else
# define DEBUG_PUTS(str)
# define DEBUG_PRINTF(fmt, ...)
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

string S1,S2;

void solve(){
    return;
}

signed main(){
    cin >> S1 >> S2;
    int num=0;
    int num1 = 0, num2= 0;
    rep(i,2){
        if(S1[i] == '#'){
            num++;
            num1++;
        }
        if(S2[i] == '#'){
            num++;
            num2++;
        }
    }
    if(num1 == 2 || num2 == 2){
        cout << "Yes" << endl;
        return 0;
    }
    if(num == 2){
        if(S1[0] == S2[0]){
            cout << "Yes" << endl;
            return 0;    
        }
        cout << "No" << endl;
        return 0;    
    }else{
        cout << "Yes" << endl;
        return 0;
    }
    return 0;
}