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

int D,N;
int T[210];
int A[210];
int B[210];
int C[210];

// dp[i][j]:i日目に、j番目の服を着たときの最大値
int dp[210][210];

signed main(){
   cin >> D >> N;
   rep(i,D){cin >> T[i];}
   rep(i,N){cin >> A[i] >> B[i] >> C[i];}


   // 初日
   rep(j,N){
      if(T[0] < A[j] || B[j] < T[0]){
            dp[0][j] = -1;
      }
      else{
         dp[0][j] = 100;
      }
   }

   // 2日目以降
   rep(i,1,D){
      rep(j,N){
         if(T[i] < A[j] || B[j] < T[i]){
            dp[i][j] = -1;
         }
         else{
            rep(k,N){
               chmax(dp[i][j],dp[i-1][k] + abs(C[k]-C[j]));
            }
         }
      }
   }
   /*
   rep(i,D){
      rep(j,N){
         cout << dp[i][j] << " ";
      }
      cout << endl;
   }
   */

   int result  = 0;
   rep(j,N){
      result = max(result,dp[D-1][j]);
   }
   cout << result-100 << endl;
   return 0;
}