#include <bits/stdc++.h>
 
using namespace std;
#define int long long
const int INF = 1LL << 60;
 
// 便利関数
// ...繰り返し
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,n,m) for(int i=n;i<m;++i)
#define ALL(x) (x).begin(),(x).end()
 
// ...比較入れ替え
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
 
//============================================================================
//ここまでテンプレ
//============================================================================
 
int H,W;
 
void solve(){
    if(H==1 || W==1) {
        cout << H*W << endl;
    }else{
        if(H%2==1)H++;
        if(W%2==1)W++;
        cout << H/2 * W/2 << endl;
    }
}
 
signed main(){
    cin >> H >> W;
    solve();
    return 0;
}