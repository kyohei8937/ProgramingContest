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

int N, X;
int total[51],patty[51];


// https://blog.hamayanhamayan.com/entry/2018/12/09/101457
int f(int level, int x){
    // level = 0 ならパティ1枚なので1を返す。
    if(level == 0) {
        return 1;
    }

    // それ以外なら、下からx番目のxが5パーツに別れてるうちのどこに含まれるかを見る。
    // 1. x=0 : バン1枚
    if(x < 1) {
        return 0;
    }
    x--;

    // 2. 1≦x≦tot[level-1] : レベルL-1バーガー
    if(x < total[level - 1]) {
        return f(level -1, x);
    }
    x -= total[level - 1];

    // 3. x=tot[level-1]+1 : パティ1枚
    if(x < 1) {
        return patty[level - 1] + 1;
    }
    x--;

    // 4. tot[level-1]+2≦x≦2*tot[level-1]+1 : レベルL-1バーガー
    if(x < total[level - 1]) {
        return patty[level-1] + 1 + f(level -1, x);
    }
    x -= total[level - 1];

    // 5. x=tot[level-1]+2 : バン1枚
    return patty[level-1] * 2 + 1;
}



signed main(){
    cin >> N >> X;

    total[0] = 1;
    patty[0] = 1;
    rep2(i,1,N+1){
        total[i] = total[i-1] * 2 +3;
        patty[i] = patty[i-1] * 2 +1;
    }
    cout << f(N,X) << endl;

    return 0;
}