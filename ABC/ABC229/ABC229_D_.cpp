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
template <typename T> T median(std::vector<T>& c) { size_t n = c.size() / 2; std::nth_element(c.begin(), c.begin() + n, c.end()); return c[n]; }
// ...べき乗のmodで割った余り
int modpow(int a, int n, int mod) { int res = 1; while (n > 0) { if (n & 1) res = res * a % mod; a = a * a % mod; n >>= 1; }return res; }

//============================================================================
//ここまでテンプレ
//============================================================================

string S;
int K;

void solve() {

    int n = S.size()-1;
    int right = 0;
    int maxLength = -1;
    int lastK = K;
    if(S[0] == '.')lastK--;
    for (int left = 0; left <= n; ++left) {
        if(right < left) {
            right = left;
            if(S[right] == '.'){
                lastK--;
            }
        }
        while (right < n && (S[right + 1] == 'X' || lastK >= 1) && lastK!=-1) {
            if (S[right + 1] == '.') {
                lastK--;
            }
            ++right;
        }

        int length = right - left + 1;
        if(length == 1 && S[right] == '.'){
            if(K==0){
                length = 0;
            }else{
                length = 1;
            }
        }
        if (length > maxLength) {
            maxLength = length;
        }
        _PRINTF("%lld-%lld:%lld(max:%lld)\n", left + 1, right + 1, length, maxLength);
        if(S[left]=='.'){
            lastK++;
        }
    }
    cout << maxLength << endl;
    return;
}

signed main() {
    cin >> S >> K;
    solve();
    return 0;
}