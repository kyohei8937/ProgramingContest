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
template <typename T> T median(vector<T>& c){size_t n = c.size() / 2;nth_element(c.begin(), c.begin() + n, c.end());return c[n];}
// ...べき乗のmodで割った余り
int modpow(int a, int n, int mod) {int res = 1;while (n > 0) {if (n & 1) res = res * a % mod;a = a * a % mod;n >>= 1;}return res;}

//============================================================================
//ここまでテンプレ
//============================================================================

int A,B;

void solve(){

	stringstream ssA;
	ssA << bitset<60>(A);
	string strA = ssA.str(); 

	stringstream ssB;
	ssB << bitset<60>(B);
	string strB = ssB.str(); 
	cout << strA << endl;
	cout << strB << endl;

	vector<int> ans;

	bool isDisp = false;
	rep(i,60){
		if(isDisp){
			if(strA[i] != strB[i]){
				ans.push_back(1);
			}else{
				ans.push_back(0);
			}
		}else{
			if(strA[i] != '0' || strB[i] != '0'){
				isDisp = true;
				ans.push_back(1);
			}
		}
	}
	int anser = 0;
	rep(i,ans.size()){
		anser += ans[ans.size()-1-i] * pow(2,i);
	}
	cout << anser << endl;
    return;
}

signed main(){
    cin >> A >> B;
    solve();
    return 0;
}