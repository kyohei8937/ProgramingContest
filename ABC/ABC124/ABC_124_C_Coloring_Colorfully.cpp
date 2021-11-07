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

string S;

void solve(){
    int count_0 = 0,count_1 = 0;
    rep(i,S.size()){
        if(i%2==0){
            if(S[i]=='1'){
                count_0++;
            }
        }else{
            if(S[i]=='0'){
                count_0++;
            }
        }
    }

    rep(i,S.size()){
        if(i%2==0){
            if(S[i]=='0'){
                count_1++;
            }
        }else{
            if(S[i]=='1'){
                count_1++;
            }
        }
    }

    cout << min(count_0,count_1) << endl;

    return;
}

signed main(){
    cin >> S;
    solve();
    return 0;
}