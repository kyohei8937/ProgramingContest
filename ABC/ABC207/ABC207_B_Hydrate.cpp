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

int A,B,C,D;

void solve(){
    if(B>=(C*D)){
        cout << -1 << endl;
        return;
    }

    int w_sum = A;
    int r_sum = 0;
    int count = 0;
    while(w_sum > (r_sum*D)){
        w_sum += B;
        r_sum += C;
        count++;
    }
    cout << count << endl;
}

signed main(){
    cin >> A >> B >> C >> D;
    solve();
    return 0;
}