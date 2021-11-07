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

int A,B,C;
vector<int> num;

void solve(){
    sort(ALL(num));
    cout << num[2] + num[1] << endl;
}

signed main(){
    cin >> A >> B >> C;
    num.push_back(A);
    num.push_back(B);
    num.push_back(C);
    solve();
    return 0;
}