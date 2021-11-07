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

int N;
int A[10][10];
int M;
int X[45],Y[45];

void solve(){

    // 順列全探索
    vector<int> one_case;
    for (int i = 0; i < N; i++) { // one_case = {0,1,2,3,...n-1} とする
        one_case.emplace_back(i);
    }

    int ans = INF;
    do {
        int time = 0;
        rep(i,one_case.size()){
            // 仲悪いチェック
            rep(j,M){
                if(i!=0){
                    if((one_case[i] == X[j] && one_case[i-1] == Y[j]) || (one_case[i] == Y[j] && one_case[i-1] == X[j])){
                        time = INF;
                        break;
                    }
                }
            }
            time += A[one_case[i]][i];
        }
        chmin(ans,time);
    } while (next_permutation(one_case.begin(), one_case.end()));

    if(ans!=INF){
        cout << ans << endl;
    }else{
        cout << -1 << endl;
    }
}

signed main(){
    cin >> N;
    rep(i,N){
        rep(j,N){
            cin >> A[i][j];
            A[i][j];
        }
    }
    cin >> M;
    rep(i,M){
        cin >> X[i] >> Y[i];
        X[i]--;
        Y[i]--;
    }
    solve();
    return 0;
}