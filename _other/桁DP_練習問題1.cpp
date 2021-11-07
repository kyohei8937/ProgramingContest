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

// https://qiita.com/pinokions009/items/1e98252718eeeeb5c9ab
// https://qiita.com/hibit/items/79ec62c4b469fbd66761

string N;

// dp[ i ][smaller][ j ] := i桁目が
// ただし smaller が true ならNより小さい場合を考え、smallerが false ならNと同じ場合を考える。
int dp[100100][2][2];

signed main(){
    cin >> N;
    N = "0" + N;
    int n = N.size();
    dp[0][0][0] = 1; //余裕がなくて3を含んでいない、ゴミ
    dp[0][0][1] = 0; //余裕がないが3を含んでいる
    dp[0][1][0] = 0; //余裕はあるが3を含んでいない
    dp[0][1][1] = 0; //余裕もあるし3も含んでいる、エリート

    rep(i,n-1) {
        // 余裕がない組
        rep(j,(N[i+1]-'0')){
            dp[i+1][1][1] += dp[i][0][1];
            if(j == 3){
                dp[i+1][1][1] += dp[i][0][0];
            }else{
                dp[i+1][1][0] += dp[i][0][0];
            }
        }
        dp[i+1][0][1] += dp[i][0][1];
        if((N[i+1]-'0') == 3){
            dp[i+1][0][1] += dp[i][0][0];
        }else{
            dp[i+1][0][0] += dp[i][0][0];
        }
        // 余裕がある組
        rep(j,10){
            dp[i+1][1][1] += dp[i][1][1];
            if(j == 3){
                dp[i+1][1][1] += dp[i][1][0];
            }else{
                dp[i+1][1][0] += dp[i][1][0];
            }            
        }
        //cout << dp[i+1][0][0] << " " << dp[i+1][0][1] << " "  << dp[i+1][1][0] << " "  << dp[i+1][1][1] << endl;
    }
    cout << dp[n-1][0][1] + dp[n-1][1][1] << endl;
    return 0;
}