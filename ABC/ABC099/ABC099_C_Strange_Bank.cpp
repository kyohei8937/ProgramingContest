#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// タイプ定義
typedef long long llong;
// 値定義
const llong INF = 1LL << 60;

// マクロ
// ...繰り返し
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(llong i=llong(a);i<llong(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
// ...比較入れ替え
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const llong MAX_MONEY = 101000;

llong N;
vector<llong> moneyList;
llong dp[MAX_MONEY][12];

int main()
{
    cin >> N;

    rep(i,MAX_MONEY){
        rep(j,12){
            dp[i][j] = INF;
        }
    }

    llong money = 1;
    moneyList.push_back(money);
    while (true)
    {
        money = money * 6;
        if(money > MAX_MONEY) break;
        moneyList.push_back(money);
    }
    money = 9;
    moneyList.push_back(money);
    while (true)
    {
        money = money * 9;
        if(money > MAX_MONEY) break;
        moneyList.push_back(money);
    }
    sort(moneyList.begin(),moneyList.end());


    rep(j,moneyList.size()){
        dp[0][j] = 0;
    }

    rep(i,1,N+1) {
        //cout << "i:" << i << " - ";
        rep(j,moneyList.size()){
            // moneyList[j]を使用する
            if((i-moneyList[j]) >= 0){
                chmin(dp[i][j],dp[i-moneyList[j]][j] + 1); 
            }
            // moneyList[j]を使用しない
            if(j != 0) { 
                chmin(dp[i][j],dp[i][j-1]);
            }
            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }
    cout << dp[N][moneyList.size()-1] << endl;
    return 0;
}
