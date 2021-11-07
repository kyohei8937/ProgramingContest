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
template <typename T> T median(std::vector<T>& c) { size_t n = c.size() / 2; std::nth_element(c.begin(), c.begin() + n, c.end()); return c[n]; }
// ...べき乗のmodで割った余り
int modpow(int a, int n, int mod) { int res = 1; while (n > 0) { if (n & 1) res = res * a % mod; a = a * a % mod; n >>= 1; }return res; }

//============================================================================
//ここまでテンプレ
//============================================================================

#define MAX 1000000000000

int K;

// 約数列挙
vector<int> enum_divisors(int N) {
	vector<int> res;
	for (int i = 1; i * i <= N; ++i) {
		if (N % i == 0) {
			res.push_back(i);
			// 重複しないならば i の相方である N/i も push
			if (N / i != i) res.push_back(N / i);
		}
	}
	// 小さい順に並び替える
	sort(res.begin(), res.end());
	return res;
}

void solve() {

	vector<int> divisorArray = enum_divisors(K);
	/*
	rep(i,divisorArray.size()){
	cout << divisorArray[i] << " ";
	}
	cout << endl;
	*/

	if (divisorArray.size() == 1) {
		cout << 1 << endl;
		return;
	}

	int ans = 1 + (divisorArray.size() - 2) / 2;

	
	if (divisorArray.size() >= 6) {
		rep2(i, 1, divisorArray.size() /2 - 1) {
			rep2(j, i + 1, divisorArray.size() / 2) {
				if (K % (divisorArray[i] * divisorArray[j]) == 0) {
					int target = K / divisorArray[i] / divisorArray[j];
					if (target >= divisorArray[i] && target <= divisorArray[j]) {
						continue;
					}
					if (binary_search(divisorArray.begin() + j, divisorArray.end(), target)) {
						//printf("%lld %lld %lld\n", divisorArray[i], divisorArray[j], target);
						ans++;
					}
				}
			}
		}
	}
	
	/*
	if (divisorArray.size() >= 6) {
		rep2(i, 1, divisorArray.size() - 4) {
			rep2(j, i + 1, divisorArray.size() - 3) {
				rep2(k, j + 1, divisorArray.size() - 2) {
					if (divisorArray[i] * divisorArray[j] * divisorArray[k] == K) {
						//printf("%lld %lld %lld\n", divisorArray[i],divisorArray[j],divisorArray[k]);
						ans++;
						break;
					}
				}
			}
		}
	}
	*/

	if (divisorArray.size() >= 4) {
		rep2(i, 1, divisorArray.size() / 2) {
			if (K % (divisorArray[i] * divisorArray[i]) == 0) {
				int target = K / (divisorArray[i] * divisorArray[i]);
				if (binary_search(divisorArray.begin(), divisorArray.end(), target)) {
					//printf("%lld %lld %lld\n", divisorArray[i], divisorArray[i], target);
					ans++;
				}
			}
		}
	}

	if (divisorArray.size() % 2 == 1) {
		ans++;
	}

	cout << ans << endl;

	return;
}

signed main() {
	cin >> K;
	solve();
	return 0;
}