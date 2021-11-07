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

#define MAX_N 10000
#define MAX_L 1000000
#define MAX_P 1000000

int L,P,N;
int A[MAX_N+1],B[MAX_N+1];

signed main(){

    cin >> N >> L >> P;
    rep(i,N){
        cin >> A[i] >> B[i];
    }

    // 簡略化のためにゴールをガソリンスタンドに追加
    A[N] = L;
    B[N] = 0;
    N++;

    // ガソリンスタンドを管理するキュー
    priority_queue<int> que;

    // ans：補給回数、pos：今いる場所、tank：タンクのガソリンの量
    int ans = 0, pos = 0, tank = P;

    rep(i,N){
        // 次に進む距離
        int d = A[i] - pos;

        // 十分な量になるまでガソリンを補給
        while(tank - d < 0){
            if(que.empty()){
                printf("-1\n");
                return 0;
            }
            tank = tank + que.top();
            que.pop();
            ans++;
        }   
        tank = tank - d;
        pos = A[i];
        que.push(B[i]);//ガソリン獲得    
    }
    printf("%lld\n",ans);
    return 0;
}