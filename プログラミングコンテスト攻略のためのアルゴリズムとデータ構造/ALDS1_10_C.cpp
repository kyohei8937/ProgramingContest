#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1LL << 60;

// 便利関数
// ...繰り返し
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=a;i<b;++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
// ...比較入れ替え
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

//============================================================================
//ここまでテンプレ
//============================================================================

int q;
string s1,s2;
int dp[1010][1010];

int solve(){
    s1 = " " + s1;
    s2 = " " + s2;
    rep(i,s1.size()){
        rep(j,s2.size()){
            dp[i][j] = 0;
        }
    }
    rep(i,1,s1.size()){
        rep(j,1,s2.size()){
            if(s1[i] == s2[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    /*
    rep(i,s1.size()){
        rep(j,s2.size()){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */
    

    return dp[s1.size()-1][s2.size()-1];
}

signed main(){

    cin >> q;
    rep(i,q){
        cin >> s1 >> s2;
        cout << solve() << endl;
    }
    return 0;
}