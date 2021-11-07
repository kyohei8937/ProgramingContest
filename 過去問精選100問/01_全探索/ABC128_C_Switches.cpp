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

int N,M;
int k[10],s[10][10];
int p[10];

signed main() {
    cin >> N >> M;
    rep(i,M){
        cin >> k[i];
        rep(j,k[i]){
            cin >> s[i][j];
        }
    }
    rep(i,M){
        cin >> p[i];
    }

    // {0, 1, ..., N-1} の部分集合の全探索
    int ok_num = 0;
    for (int bit = 0; bit < (1<<N); ++bit) {
        bool isOK = true;
        rep(i,M){
            int on_num = 0;
            rep(j,k[i]){
                if (bit & (1<<(s[i][j]-1))) {
                    on_num++;
                }
            }
            if(on_num % 2 != p[i]){
                isOK = false;
                break;
            }
        }
        if(isOK){
            ok_num++;
        }
    }

    cout << ok_num << endl;
}