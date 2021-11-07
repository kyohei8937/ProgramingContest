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
vector<int> G[100000];
int max_depth;

void solve(){
    
    // 1回目の深さ優先探索(1スタート)
    stack<int> g_stack;
    int depth[100000] = {0};
    g_stack.push(0);
    depth[0] = 1;
    int max_depth_pos = 0;
    while(!g_stack.empty()){
        int current = g_stack.top();

        bool isHit = false;
        rep(j,G[current].size()){
            int next = G[current][j];
            // 未到達の場合
            if(depth[next] == 0){
                depth[next] = depth[current]+1;
                g_stack.push(next);
                isHit = true;
                break;
            }
        }
        if(!isHit){
            g_stack.pop();
        }
    }
}

signed main(){
    cin >> N;
    rep(i,N){
        int A,B;
        cin >> A >> B;
        A--;B--;
        G[A].push_back(B);
        G[B].push_back(A);
    }
    solve();
    return 0;
}