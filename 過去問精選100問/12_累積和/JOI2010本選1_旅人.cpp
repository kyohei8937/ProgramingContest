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

int n,m;
int dis[100010];
int moveMethod[100010];
int S[100010];

void solve(){
    S[0] = 0;
    rep(i,n-1){
        S[i+1] = S[i] + dis[i];
    }

    int current = 0;
    int ans = 0;
    rep(i,m){
        int next = current + moveMethod[i];
        ans = ans + abs(S[next] - S[current]);
        current = next;
        //cout << ans << endl;
    }
    cout << ans % 100000 << endl;
}

signed main(){
    cin >> n >> m;
    rep(i,n-1){cin >> dis[i];}
    rep(i,m){cin >> moveMethod[i];}
    solve();
    return 0;
}