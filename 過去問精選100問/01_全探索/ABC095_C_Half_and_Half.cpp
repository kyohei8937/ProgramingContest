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

int A,B,C,X,Y;

signed main(){
    cin >> A >> B >> C >> X >> Y;

    int num_max = max(X,Y);
    int min_Sum = INF;
    rep(i,num_max+1){
        // ABピザの枚数
        int num_AB = i*2;

        // Aピザの枚数
        int num_A = X - i;

        // Bピザの枚数
        int num_B = Y - i;

        if(num_A < 0) num_A = 0;
        if(num_B < 0) num_B = 0;

        int sum = num_AB * C + num_A * A + num_B * B;
        chmin(min_Sum, sum);
    }
    cout << min_Sum << endl;

    return 0;
}