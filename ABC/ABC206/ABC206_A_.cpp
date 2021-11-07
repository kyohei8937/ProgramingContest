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

double N;

void solve(){
    if((int)(N*1.08) < 206){
        cout << "Yay!" << endl;
    }else if ((int)(N*1.08) > 206){
        cout << ":(" << endl;
    }else{
        cout << "so-so" << endl;
    }
}

signed main(){
    cin >> N;
    solve();
    return 0;
}