#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1LL << 60;
const int MOD = 1000000007;

// 便利関数
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,n,m) for(int i=n;i<m;++i)
#define ALL(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

//============================================================================
//ここまでテンプレ
//============================================================================
const int N_MAX = (400);
const int M_MAX = N_MAX * (N_MAX-1) / 2;
int N,M;
int ans;

struct Edge {
    int to;
    int cost;
};
using Graph = vector<vector<Edge>>;
using P = pair<int, int>;
Graph G;

void dijkstra(int s, vector<int> &dis, int g, int k) {
    int N = G.size();
    dis.resize(N, INF);
    priority_queue<P, vector<P>, greater<P>> pq;  // 「仮の最短距離, 頂点」が小さい順に並ぶ
    dis[s] = 0;
    pq.emplace(dis[s], s);
    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        int v = p.second;
        if (dis[v] < p.first) {  // 最短距離で無ければ無視
            continue;
        }
        for (auto &e : G[v]) {
            if(e.to <= k || e.to == g){
                if (dis[e.to] > dis[v] + e.cost) {  // 最短距離候補なら priority_queue に追加
                    dis[e.to] = dis[v] + e.cost;
                    pq.emplace(dis[e.to], e.to);
                }
            }
        }
    }
}

signed main(){
    cin >> N >> M;
    G.resize(N);
    rep(i,M){
        int a,b,c;
        cin >> a>> b>> c;
        a--;b--;
        G[a].push_back({b,c});
    }
    
    return 0;
}