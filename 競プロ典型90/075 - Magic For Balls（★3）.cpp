#include <bits/stdc++.h>

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

int N;

vector<pair<int, int> > prime_factorize(int N) {
    vector<pair<int, int> > res;
    for (int a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        int ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}

signed main() {
    int N;
    cin >> N;
    const auto &res = prime_factorize(N);
	int count = 0;
    //cout << N << ":";
    for (auto p : res) {
        for (int i = 0; i < p.second; ++i) {
			//cout << " " << p.first;
			count++;
		}
    }
    //cout << endl;
	//cout << count << endl;

	int i = 0;
	while(modpow(2, i, MOD) < count){
		i++;
	}
	cout << i << endl;
}