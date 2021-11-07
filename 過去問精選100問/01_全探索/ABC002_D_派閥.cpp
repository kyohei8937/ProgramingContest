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
int x[66],y[66];

signed main() {
    cin >> N >> M;
    vector<int> graph[12];
    rep(i,M){
        cin >> x[i] >> y[i];
        graph[x[i]-1].push_back(y[i]-1);
        graph[y[i]-1].push_back(x[i]-1);
    }

    // {0, 1, ..., N-1} の部分集合の全探索
    int result = 0;
    for (int bit = 0; bit < (1<<N); ++bit) {
        bool isOK = true;
        rep(i,N){
            if(bit >> i & 1){
                rep(j,0,N){
                    if(i==j)continue;

                    if(bit & (1 << j)){
                        if (find(graph[i].begin(), graph[i].end(), j) == graph[i].end()) {
                            isOK = false;
                            break;
                        }
                    }                    
                }
            }
            if(!isOK){
                break;
            }
        }
        if(isOK){
            result = max(result,(int)__builtin_popcount(bit));
        }
    }
    cout << result << endl;
    return 0;
}