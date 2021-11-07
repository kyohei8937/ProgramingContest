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
pair<int,int> pos[8];
signed main() {
    cin >> N;
    rep (i,N) {
        cin >> pos[i].first >> pos[i].second;
    }

    int P[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    double distance = 0.0;
    do {
        for (int i = 0; i < N - 1; i++) {
            int x_dis = pos[P[i+1]].first - pos[P[i]].first;
            int y_dis = pos[P[i+1]].second - pos[P[i]].second;
            distance = distance + sqrt(pow((double)x_dis,2.0) + pow((double)y_dis,2.0));
        }
    } while(next_permutation(P, P + N));

    int mod = 1;
    rep(i,1,N+1) {
        mod = mod * i;
    }

    double ans = distance / (double)mod;
    printf("%.16f\n",ans);
    return 0;
}