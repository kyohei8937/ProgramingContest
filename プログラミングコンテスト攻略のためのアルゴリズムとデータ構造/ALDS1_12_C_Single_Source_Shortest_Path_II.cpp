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

// https://algo-logic.info/dijkstra/

struct Edge {
    int to;
    int cost;
};
using Graph = vector<vector<Edge>>;

/* dijkstra(G,s,dis)
    入力：グラフ G, 開始点 s, 距離を格納する dis
    計算量：O(|E|log|V|)
    副作用：dis が書き換えられる
*/
void dijkstra(const Graph &G, int s, vector<int> &dis) {
    int N = G.size();
    dis.assign(N, INF); // INFで初期化
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // 「仮の最短距離, 頂点」が小さい順に並ぶ
    dis[s] = 0;
    pq.push(make_pair(dis[s], s)); 
    while (!pq.empty()) {
        pair<int, int> p = pq.top();
        pq.pop();
        int v = p.second;
        if (dis[v] < p.first) {  // 最短距離で無ければ無視
            continue;
        }
        for (auto &e : G[v]) {
            if (dis[e.to] > dis[v] + e.cost) {  // 最短距離候補なら priority_queue に追加
                dis[e.to] = dis[v] + e.cost;
                pq.push(make_pair(dis[e.to], e.to)); 
            }
        }
    }
}

signed main(){
    Graph G;
    int s = 0;
    vector<int> dis;

    int n,k,u;
    cin >> n;
    rep(i,n){
        cin >> u >> k;
        vector<Edge> tmpEdgeArray;
        rep(j,k){
            Edge tmpEdge;
            cin >> tmpEdge.to >> tmpEdge.cost;
            tmpEdgeArray.push_back(tmpEdge);
        }
        G.push_back(tmpEdgeArray);
    }
    dijkstra(G,s,dis);

    rep(i,n){
        cout << i << " " << dis[i] << endl; 
    }

    return 0;
}