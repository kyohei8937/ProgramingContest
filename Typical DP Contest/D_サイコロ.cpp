#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

// タイプ定義
#define int long long
// 値定義
const int INF = 1LL << 60;

// マクロ
// ...繰り返し
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=a;i<b;++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
// ...比較入れ替え
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int N,D;
double dp[100][100][100][100];

constexpr int dx[6] = {0, 1, 0, 2, 0, 1};
constexpr int dy[6] = {0, 0, 1, 0, 0, 1};
constexpr int dz[6] = {0, 0, 0, 0, 1, 0};

signed main(){

    cin >> N >> D;

    int c2=0,c3=0,c5=0;
    while(D%2==0){D/=2;c2++;}
    while(D%3==0){D/=3;c3++;}
    while(D%5==0){D/=5;c5++;}
    if(D != 1){
        cout << 0 << endl;
        return 0;
    }
    printf("c2:%lld,c3:%lld,c5:%lld,\n",c2,c3,c5);

    dp[0][0][0][0] = 1.0;
    rep(i,N){
        rep(pc2,c2+1){
            rep(pc3,c3+1){
                rep(pc5,c5+1){
                    rep(j,6) {
                        int nc2 = min(c2, pc2 + dx[j]);
                        int nc3 = min(c3, pc3 + dy[j]);
                        int nc5 = min(c5, pc5 + dz[j]);
                        dp[(i+1)&1][nc2][nc3][nc5]+=dp[i&1][pc2][pc3][pc5]/6.0;
                    }
                    dp[i&1][pc2][pc3][pc5]=0;
                }
            }
        }
    }
    cout << dp[N&1][c2][c3][c5] << endl;
    return 0;
}