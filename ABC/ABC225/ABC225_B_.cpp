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
int S1,S2;

void solve(){
    return;
}

signed main(){
    cin >> N;
    cin >> S1 >> S2;
    bool ret = true;
    rep2(i,1,N-1){
        int s1,s2;
        cin >> s1 >> s2;
        if((S1 == s1 || S1 == s2) &&(S2 == s1 || S2 == s2) ){
            continue;
        }
        else if(((S1 != s1) &&(S1 != s2)) && (S2 == s1) ||(S2 == s2)){
            S1 = -1;
        }
        else if(((S2 != s1) &&(S2 != s2)) && (S1 == s1) ||(S1 == s2)){
            S2 = -1;
        }else{
            ret = false;
            S1 = -1;
            S2 = -1;
        }
    }
    if(ret){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}