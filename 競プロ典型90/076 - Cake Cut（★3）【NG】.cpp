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

#define N_MAX 100000

int N;
int A[N_MAX*2];
int sum;

void solve(){

    if(sum%10 != 0){
        cout << "No" << endl;
        return;
    }
    int target = sum / 10;

    int right = 0;
    int current_sum = 0;
    for (int left = 0; left < N; ++left) {
        while (right < N && current_sum < target) {
            current_sum += A[right];
            if(current_sum == target){
                cout << "Yes" << endl;
                return;
            }
            ++right;
        }

        /* break した状態で right は条件を満たす最大なので、何かする */
        // ex: res += (right - left);

        /* left をインクリメントする準備 */
        if (right == left) {
            ++right;
        }
        else {
            current_sum -= A[left];
            if(current_sum == target){
                cout << "Yes" << endl;
                return;
            }
        }
    }

    cout << "No" << endl;

    return;
}

signed main(){
    cin >> N;
    rep(i,N) {
        cin >> A[i];
        sum += A[i];
    }
    rep(i,N) {
        A[i+N] = A[i];
    }
    N = 2 * N;
    solve();
    return 0;
}