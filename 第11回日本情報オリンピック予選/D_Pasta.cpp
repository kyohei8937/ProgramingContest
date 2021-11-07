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

int N,K;
int C[110];

//dp[i][a][b]= i−1 日目までのパスタの選び方で、
//i−2 日目のパスタが a、i−1 日目までのパスタが b であるようなものの総数
int dp[110][3][3];

signed main(){
   
   cin >> N >> K;
   rep(i,N){C[i]= -1;}
   rep(i,K){
      int A,B;
      cin >> A >> B;
      C[A] = B-1;
   }

   // 1日目
   rep(j,3){
      rep(k,3){
         if(C[1] == -1 && C[2] == -1){
            dp[1][j][k] = 1;
         }else if(C[1] != -1 && C[2] != -1){
            dp[1][C[1]][C[2]] = 1;
         }else if(C[1] == -1 && C[2] != -1){
            dp[1][j][C[2]] = 1;            
         }else if(C[1] != -1 && C[2] == -1){
            dp[1][C[1]][k] = 1;            
         }
      }
   }

   // 2日目以降
   rep(i,2,N+1){
      rep(j,3){
         rep(k,3){

         }
      }
   }

   return 0;
}