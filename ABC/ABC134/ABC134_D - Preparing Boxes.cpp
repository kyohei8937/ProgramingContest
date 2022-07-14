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
vector<int> a;

/*  divisor(n)
    入力：整数 n
    出力：nのすべての約数
    計算量：O(√n)
*/
vector<int> divisor(int n) {
    vector<int> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}

void solve(){
    vector<int> ans;
    vector<int> tmp_a = a;
    for(int i = N -1; i >= 0; i--){
        int num = i+1;
        if(tmp_a[i] == 1){
            ans.push_back(num);
            vector<int> yakusuArray = divisor(num);
            rep(j,yakusuArray.size()){
                int yakusu = yakusuArray[j];
                _printf("%lld ", yakusu);
                if(tmp_a[yakusu-1] == 0){
                    tmp_a[yakusu-1] = 1;
                }else{
                    tmp_a[yakusu-1] = 0;
                }
            }
            _printf("%s","\n");
        }
    }

    sort(ALL(ans));
    cout << ans.size() << endl;
    rep(i,ans.size()){
        cout << ans[i];
        if(i!=ans.size()-1){
            cout << " ";
        }else{
            cout << endl;
        }
    }
    return;
}

signed main(){
    cin >> N;
    a.resize(N);
    rep(i,N){
        cin >> a[i];
    }
    solve();
    return 0;
}