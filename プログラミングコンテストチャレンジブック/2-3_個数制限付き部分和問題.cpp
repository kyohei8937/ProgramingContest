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

int n,k;
int a[100],m[100];
int dp[110][100100];

signed main(){
    
    cin >> n >> k;
    rep(i,n){
        cin >> a[i] >> m[i];
    }

    memset(dp,-1,sizeof(int)*110*100100);

    rep(i,n){
        dp[i][0] = m[i];
    }

    rep(i,n){
        int last_num = dp[i][0];
        rep(j,1,k+1) {
            if(i-1 >= 0 && dp[i-1][j] >= 0){
                dp[i][j] = last_num;
            }
            else if(j-a[i] >= 0 && dp[i][j-a[i]] >= 1){
                dp[i][j] = dp[i][j-a[i]]-1;
                last_num--;
            }
        }
    }
    /*
    rep(i,n){
        rep(j,k) {
            printf("%3lld ",dp[i][j]);
        }
        cout << endl;
    }
    */

    if(dp[n-1][k] >= 0){
        printf("Yes\n");
    }else{
        printf("No\n");
    }

    return 0;
}