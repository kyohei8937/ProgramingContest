#include <bits/stdc++.h>
#include <cmath>
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

#define PI 3.14159265359

int T, L, X, Y, Q;
vector<int> E;
void solve();

double degreeToRadiun(double input) {
	return PI * input / 180.0;
}

signed main() {
	cin >> T;
	cin >> L >> X >> Y;
	cin >> Q;
	E.resize(Q);
	rep(i, Q) { cin >> E[i]; }
	solve();
	return 0;
}

void solve() {
	rep(i, Q) {

		// 半径を求める
		double hankei = (double)L / 2.0;

		// 角度を求める
		double degree = 360.0 * (double)E[i] / (double)T;

		double takasa, y;
		if (degree == 0) {
			takasa = 0.0;
			y = 0.0;
		}
		else if (0 < degree && degree < 90) {
			takasa = hankei * cos(degreeToRadiun(degree));
			y = -1 * hankei * cos(degreeToRadiun(90 - degree));
		}
		else if (degree == 90) {
			takasa = hankei;
			y = -hankei;
		}
		else if (90 < degree && degree < 180) {
			takasa = hankei + hankei * cos(degreeToRadiun(90 - (degree - 90)));
			y = -1 * hankei * cos(degreeToRadiun(degree - 90));
		}
		else if (degree == 180) {
			takasa = L;
			y = 0.0;
		}
		else if (180 < degree && degree < 270) {
			takasa = hankei + hankei * cos(degreeToRadiun(degree - 180));
			y = hankei * cos(degreeToRadiun(90 - (degree - 180)));
		}
		else if (degree == 270) {
			takasa = hankei;
			y = hankei;
		}
		else if (270 < degree && degree < 360) {
			takasa = hankei * cos(degreeToRadiun(90 - (degree - 270)));
			y = hankei * cos(degreeToRadiun(degree - 270));
		}

		// (0,y,0) と (X,Y,0) の距離（底辺）を求める
		double teihen = sqrt(pow(X - 0, 2) + pow(Y - y, 2) + pow(0 - 0, 2));
		double ans = atan(takasa / teihen) * 180 / PI;

		printf("角度：%lf, 高さ：%lf, y:%lf, 底辺：%lf, 俯角：%lf\n", degree, takasa, y, teihen, ans);
		printf("%.12f\n", ans);
	}
}
