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
int A,B,C;

signed main(){
    cin >> A >> B >> C;

    bool isGusu = false;
    if(C%2 == 0){
        isGusu = true;
    }

    // AもBも0以上
    if(A>=0 && B>=0){
        if(A<B){
            cout << "<" << endl;
        }else if(A>B){
            cout << ">" << endl;
        }else if(A==B){
            cout << "=" << endl;
        }
    }
    // Aは0以上だがBは0未満
    else if(A>=0 && B<0){
        // 偶数べき乗なら絶対値で比較
        if(isGusu){
            if(abs(A)<abs(B)){
                cout << "<" << endl;
            }else if(abs(A)>abs(B)){
                cout << ">" << endl;
            }else if(abs(A)==abs(B)){
                cout << "=" << endl;
            }
        }
        // 奇数べき乗ならAの勝ち
        else{
            cout << ">" << endl;
        }
    }
    // Aは0未満だがBは0以上
    else if(A<0 && B>=0){
        // 偶数べき乗なら絶対値で比較
        if(isGusu){
            if(abs(A)<abs(B)){
                cout << "<" << endl;
            }else if(abs(A)>abs(B)){
                cout << ">" << endl;
            }else if(abs(A)==abs(B)){
                cout << "=" << endl;
            }
        }
        // 奇数べき乗ならBの勝ち
        else{
            cout << "<" << endl;
        }
    }
    // AもBも0未満
    else{
        // 偶数べき乗なら絶対値で比較
        if(isGusu){
            if(abs(A)<abs(B)){
                cout << "<" << endl;
            }else if(abs(A)>abs(B)){
                cout << ">" << endl;
            }else if(abs(A)==abs(B)){
                cout << "=" << endl;
            }
        }
        // 奇数べき乗ならそのまま
        else{
            if(A<B){
                cout << "<" << endl;
            }else if(A>B){
                cout << ">" << endl;
            }else if(A==B){
                cout << "=" << endl;
            }
        }        
    }

    return 0;
}