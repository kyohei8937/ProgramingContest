#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1LL << 60;
const int MOD = 1000000007;

// マクロ
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,n,m) for(int i=n;i<m;++i)
#define ALL(x) (x).begin(),(x).end()

//#define RANDOM_CHECK
#define DEBUG
#ifdef DEBUG
# define _printf(fmt, ...)  printf(fmt, __VA_ARGS__);                   
#else
# define _printf(fmt, ...)
#endif

// 便利関数
// ...最小値・最大値交換
template<class T> inline bool ChMin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool ChMax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
// ...中央値
template <typename T> T Median(std::vector<T>& c){size_t n = c.size() / 2;std::nth_element(c.begin(), c.begin() + n, c.end());return c[n];}
// ...べき乗のmodで割った余り
int ModPow(int a, int n, int mod) {int res = 1;while (n > 0) {if (n & 1) res = res * a % mod;a = a * a % mod;n >>= 1;}return res;}
// ...最大公約数
int GCD(int a, int b) {if (b==0) return a;else return GCD(b, a%b);}
// ...最小公倍数
int LCM(int a, int b) {return a * b / GCD(a, b);}

//============================================================================
//ここまでテンプレ
//============================================================================
#ifndef RANDOM_CHECK
const int N_MAX = 100000;
int N;
vector<int> children[N_MAX];

int hashi;
int max_score;

vector<int> gusu;
vector<int> kisu;

// 再帰関数による実装
void dfs(int current, int prev, int score){
	for(int next:children[current]){
		if(next!=prev){
            if(max_score < score) {
                hashi = next;
                max_score = score;
            }
			dfs(next,current, score+1);
		}
	}
}

// 再帰関数による実装
void dfs2(int current, int prev, int score){
	for(int next:children[current]){
		if(next!=prev){
            if(max_score < score) {
                hashi = next;
                max_score = score;
            }
            if(score % 2 == 0) {
                gusu.push_back(next);
            }else {
                kisu.push_back(next);
            }
			dfs(next,current, score+1);
		}
	}
}

signed main() {
	// 標準入力
	cin >> N;
    int start = 0;
	rep(i,N-1){
		int a,b;
		cin >> a >> b;
		a--;b--;
		children[a].push_back(b);
		children[b].push_back(a);
        start = a;
	}
    dfs(start,-1,1);
    int hashi1 = hashi;
    max_score = 0;
    kisu.push_back(hashi1);
    dfs2(hashi1,-1,1);
    int hashi2 = hashi;
	return 0;
}
#else // RANDOM_CHECK
//============================================================================
//ここからランダムチェッカー用
//============================================================================
int solve_fast(){
    return 0;
}
// ここに愚直法を書く
int solve_Jury(){
    return 0;
}

void random_generate() {
    // ここでランダム生成をする。例えば次のような感じ。
    // for (int i = 0; i < N; i++) A[i] = rand() % 10 + 1;
    // for (int i = 0; i < N; i++) B[i] = rand() % 10 + 1;
}
signed main() {
    srand((unsigned int) time(NULL));
    for (int t = 1; t <= 1000; t++) {
        //N = 8; // 入力データのサイズ（適当に決めて良い）
        //A.resize(N), B.resize(N); // プログラムで使用する変数
        random_generate();
        int J1 = solve_fast();
        int J2 = solve_Jury();
        if (J1 != J2) {
            cout << "Wrong Answer on Test #" << t << endl;
            cout << "Jury = " << J2 << ", Output = " << J1 << endl;
            // テストケースを出力
            return;
        }
    }
    cout << "OK!" << endl;
    return 0;
}
#endif // RANDOM_CHECK