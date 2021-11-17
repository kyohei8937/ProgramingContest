#include <bits/stdc++.h>
#include <random>
using namespace std;
#define int long long
const int INF = 1LL << 60;
const int MOD = 1000000007;

// マクロ
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,n,m) for(int i=n;i<m;++i)
#define ALL(x) (x).begin(),(x).end()

// 便利関数
// ...最小値・最大値交換
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
// ...中央値
template <typename T> T median(std::vector<T>& c){size_t n = c.size() / 2;std::nth_element(c.begin(), c.begin() + n, c.end());return c[n];}
// ...べき乗のmodで割った余り
int modpow(int a, int n, int mod) {int res = 1;while (n > 0) {if (n & 1) res = res * a % mod;a = a * a % mod;n >>= 1;}return res;}

//============================================================================
//ここまでテンプレ
//============================================================================

// https://not522.hatenablog.com/entry/2016/03/20/005946

#define MAX 100000

int W = 100000;

// 重さ・価値
int w[MAX], v[MAX];

//--------------------------------------
// 愚直
//--------------------------------------
int guchoku(){
    // 今までに入れた物の重さの総和
    int s = 0;
    // 今までに入れた物の価値の総和
    int t = 0;

    // 入れるだけ入れる
    rep(i,MAX){
        if(s+ w[i] <= W){
            s += w[i];
            t += v[i];
        }
    }
    return t;
}

//--------------------------------------
// ビームサーチ
//--------------------------------------
int beam(){
    // ビーム幅
    const int BEAM = 100;

    // 現在の状態(価値, 重さ)
    vector<pair<int, int>> cur;
    cur.push_back(make_pair(0,0));

    // ビームサーチ
    rep(i,MAX){
        // 次の状態
        vector<pair<int, int>> next;
        rep(j, cur.size()){
            pair<int, int> s = cur[j];
            next.push_back(s);
            if(s.second + w[i] <= W){
                next.push_back(make_pair(s.first + v[i], s.second + w[i]));
            }
        }
        // 価値が大きい順に並び替え
        sort(ALL(next), greater<pair<int, int>>());
        // 状態をビーム幅に減らす
        if(next.size() > BEAM){
            next.resize(BEAM);
        }
        cur = next;
    }
    return cur[0].first;
}

//--------------------------------------
// 焼きなまし
//--------------------------------------
// 乱数生成器
inline uint32_t rnd(void) {
  static uint32_t y = 2463534242;
  y = y ^ (y << 13); y = y ^ (y >> 17);
  return y = y ^ (y << 5);
}

bool next(int b, int t) {
  if (b > 0) return true;
  return exp(b / 10000.0 / pow(0.999999, t)) > double(rnd()) / numeric_limits<uint32_t>::max();
}

int yakinamashi(){
    // ループ回数
    const int T = 10000;

    // 今までに入れた物の重さの総和
    int sum_w = 0;
    // 今までに入れた物の価値の総和
    int sum_v = 0;
    // 今までに入れた物・入れていない物
    vector<int> used, unused(MAX);

    // はじめは全て使っていない
    rep(i,MAX){
        unused[i] = 0;
    }

    // ループ
    rep(i,T){
        // 次に入れる物をランダムに選ぶ
        int k = rnd() % unused.size();

        // ナップサックに収まるようにランダムに捨てる
        int del_sum_w = 0;
        int del_sum_v = 0;
        vector<int> del;
        while((del_sum_v < v[k] + 10000) && \
              (sum_w + w[unused[k]] - del_sum_w > W)){
            // ランダムに捨てるkを生成（既に捨ててるやつならcontinue）
            int del_k = rnd() % used.size();
            if(find(ALL(del),del_k) != del.end()){
                continue;
            }
            del_sum_w += w[used[del_k]];
            del_sum_v += v[used[del_k]];
            del.push_back(del_k);
            cout << del_sum_v << ","<< v[k] << "," << sum_w << "," << w[unused[k]] << "," << del_sum_w << endl;
        }
        
        // 焼きなまし
        // スコアが改善しない時も、選んだ荷物をたまには使うようにします。
        // 選んだ荷物を使う確率は、スコアの下落幅が小さい・ループの始めのほうで大きくなるようにします。
        if(next(v[k]-del_sum_v,i)) {
            if (sum_w +w[unused[k]] - del_sum_w <= W){
                sum_w += w[k] - del_sum_w;
                sum_v += v[k] - del_sum_v;
                unused[k] = unused.back();
                unused.pop_back();
                used.push_back(k);
                sort(ALL(del), greater<int>());
                rep(j, del.size()){
                    int del_k = used.back();
                    used.pop_back();
                    unused.push_back(del_k);
                }
            }
        }
    }
    return sum_v;
}


int dp(){
    // 現在の状態(価値, 重さ)
    

    return 0;
}


signed main(){
    mt19937 mt(0);
    uniform_int_distribution<int> dist(1, 100000);
    rep(i,MAX) {
        w[i] = dist(mt);
        v[i] = dist(mt);
    }
    //cout << guchoku() << endl;
    //cout << beam() << endl;
    cout << yakinamashi() << endl;
    //cout << dp() << endl;
    return 0;
}