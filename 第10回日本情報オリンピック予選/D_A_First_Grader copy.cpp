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

int N;
int num[110];
int dp[110][21];

signed main(){

   cin >> N;
   rep(i,N){
      cin >> num[i];
   }

   dp[0][num[0]] = 1;
   rep(i,1,N-1){
      rep(j,21){
         if(dp[i-1][j] >= 1) {
            if(j-num[i]>=0){
               dp[i][j-num[i]] += dp[i-1][j];
            }
            if(j+num[i]<=20){
               dp[i][j+num[i]] += dp[i-1][j];
            }
         }
      }
   }

   /*
   rep(i,0,N-1){
      cout << "i:" << i << " - ";
      rep(j,21){
         printf("%02lld ", dp[i][j]);
      } 
      cout << endl;
   }
   */
  
   cout << dp[N-2][num[N-1]] << endl;
   return 0;
}