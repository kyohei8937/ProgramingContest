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
# define _printf(fmt, ...)  printf(fmt, __VA_ARGS__);                   
#else
# define _printf(fmt, ...)
#endif

// 便利関数
// ...最小値・最大値交換
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
// ...中央値
template <typename T> T median(std::vector<T>& c){size_t n = c.size() / 2;std::nth_element(c.begin(), c.begin() + n, c.end());return c[n];}
// ...べき乗のmodで割った余り
int modpow(int a, int n, int mod) {int res = 1;while (n > 0) {if (n & 1) res = res * a % mod;a = a * a % mod;n >>= 1;}return res;}
// ...最大公約数
int gcd(int a, int b) {if (b==0) return a;else return gcd(b, a%b);}
// ...最小公倍数
int lcm(int a, int b) {return a * b / gcd(a, b);}

//============================================================================
//ここまでテンプレ
//============================================================================

int N;
vector<int> A;

// index が条件を満たすかどうか
int isOK(int key) {
    int cur = key*2;
    bool isBad = false;
    rep(i,N){
        cur = A[i]*2 - cur;
    }
    if(cur == key*2){
        return 0;
    }else if (cur > key*2){
        return 2;
    }else{
        return 1;
    }
    return -1;
}

// 汎用的な二分探索のテンプレ
int binary_search() {
    int left = -1;
    int right = A[0]+1;

    /* どんな二分探索でもここの書き方を変えずにできる！ */
    while (right - left > 1) {
        int mid = left + (right - left) / 2;

        int ret = isOK(mid);
        _printf("key[%lld (%lld~%lld)] is ret:%lld\n", mid,left,right,ret);
        if (ret == 0) return mid*2;
        else if(ret == 1){
            right = mid;
        }else if(ret == 2){
            left = mid;
        }
    }
    return -1;
}

void solve(){
    int ans1 = binary_search();
    int cur = ans1;
    rep(i,N){
        cout << cur;
        if(i != N-1) {
            cur = A[i]*2 - cur;
            cout << " ";
        }
    }
    cout << endl;
    return;
}

signed main(){
    cin >> N;
    A.resize(N);
    rep(i,N){
        cin >> A[i];
    }
    solve();
    return 0;
}