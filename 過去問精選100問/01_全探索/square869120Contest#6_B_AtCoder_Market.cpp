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
int A[30],B[30];

signed main(){

    cin >> N;
    rep(i,N)cin >> A[i] >> B[i];

    int start, gloal;
    int min_sum = INF;
    rep(i,N){
        rep(j,N){
            int sum = 0;
            rep(k,N){
                sum = sum + abs(A[i]-A[k]);
                sum = sum + abs(A[k]-B[k]);                
                sum = sum + abs(B[k]-B[j]); 
            }
            chmin(min_sum,sum);
        }
    }

    cout << min_sum << endl;
    
    return 0;
}