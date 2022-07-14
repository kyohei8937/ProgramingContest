#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1LL << 60;
const int MOD = 1000000007;

// マクロ
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,n,m) for(int i=n;i<m;++i)
#define ALL(x) (x).begin(),(x).end()

#define DEBUG
#ifdef DEBUG
# define _printf(fmt, ...)  printf(fmt, __VA_ARGS__);                   
#else
# define _printf(fmt, ...)
#endif

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

double W,H,x,y;

vector<double> kouhoList;

bool kouten(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double &ansX,  double &ansY)
{
    if (x1 == x2 && x3 == x4) {
        return false;
    } else if (x1 == x2) {
        ansX = x1;
        ansY = (y4 - y3) / (x4 - x3) * (x1 - x3) + y3;
    } else if (x3 == x4) {
        ansX = x3;
        ansY = (y2 - y1) / (x2 - x1) * (x3 - x1) + y1;
    } else {
        double a1,a3;
        a1 = (y2 - y1) / (x2 - x1);
        a3 = (y4 - y3) / (x4 - x3);
        if (a1 == a3) {
            return false;
        } else {
            ansX = (a1 * x1 - y1 - a3 * x3 + y3) / (a1 - a3);
            ansY = (y2 - y1) / (x2 - x1) * (ansX - x1) + y1;
        }
    }
    return true;
}

void solve(){

    // 縦分割
    double kouho1_1 = H * x;
    double kouho1_2 = H * (W-x);
    kouhoList.push_back(min(kouho1_1,kouho1_2));

    // 横分割
    double kouho2_1 = W * y;
    double kouho2_2 = W * (H-y);
    kouhoList.push_back(min(kouho2_1,kouho2_2));

    double kouho;
    double koutenX, koutenY;

    // 左上と交わる
    if(kouten(0,0,x,y, 0, H,W,H,koutenX,koutenY)){
        if(koutenX <= W){
            kouho = koutenX * H / 2;
            _printf("%f %f -> %f\n", koutenX,koutenY,kouho);
            kouhoList.push_back(kouho);
        }else{
            kouten(0,0,x,y, W, 0,W,H,koutenX,koutenY);
            kouho = koutenY * W / 2;
            _printf("%f %f -> %f\n", koutenX,koutenY,kouho);
            kouhoList.push_back(kouho);
        }
    }

    // 右上と交わる
    if(kouten(W,0,x,y, 0,H,W,H,koutenX,koutenY)){
        if(koutenX >= 0){
            kouho = (W-koutenX) * H / 2;
            _printf("%f %f -> %f\n", koutenX,koutenY,kouho);
            kouhoList.push_back(kouho);
        }else{
            kouten(W,0,x,y, 0,0,0,H,koutenX,koutenY);
            kouho = koutenY * W / 2;
            _printf("%f %f -> %f\n", koutenX,koutenY,kouho);
            kouhoList.push_back(kouho);
        }
    }

    // 左下と交わる
    if(kouten(0,H,x,y, 0, 0,W,0,koutenX,koutenY)){
        if(koutenX <= W){
            kouho = koutenX * H / 2;
            _printf("%f %f -> %f\n", koutenX,koutenY,kouho);
            kouhoList.push_back(kouho);
        }else{
            kouten(0,H,x,y, W, 0,W,H,koutenX,koutenY);
            kouho = (H-koutenY) * W / 2;
            _printf("%f %f -> %f\n", koutenX,koutenY,kouho);
            kouhoList.push_back(kouho);
        }
    }

    // 右下と交わる
    if(kouten(W,H,x,y, 0, 0,W,0,koutenX,koutenY)){
        if(koutenX >= 0){
            kouho = (W-koutenX) * H / 2;
            _printf("%f %f -> %f\n", koutenX,koutenY,kouho);
            kouhoList.push_back(kouho);
        }else{
            kouten(W,H,x,y, 0, 0,0,H,koutenX,koutenY);
            kouho = (H-koutenY) * W / 2;
            _printf("%f %f -> %f\n", koutenX,koutenY,kouho);
            kouhoList.push_back(kouho);
        }
    }


    sort(ALL(kouhoList), greater<double>());

    if(kouhoList[0] == kouhoList[1]){
        printf("%.10f 1\n", kouhoList[0]);
    }else{
        printf("%.10f 0\n", kouhoList[0]);
    }
    return;
}

signed main(){
    cin >> W >> H >> x >> y;
    solve();
    return 0;
}