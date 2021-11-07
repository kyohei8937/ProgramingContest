#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
// タイプ定義
typedef long long llong;
// マクロ
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(llong i=llong(a);i<llong(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

llong N,K;
vector<pair<llong,llong>> friends;

int main()
{
    cin >> N >> K;

    rep(i,N){
        llong tmpA,tmpB;
        cin >> tmpA >> tmpB;
        friends.push_back(make_pair(tmpA,tmpB));
    }
    sort(friends.begin(), friends.end());

    llong result = 0;
    llong friendsCount = 0;
    llong currentPos = 0;
    while(true){
        // 次の友達の村があるか確認
        if(friendsCount < N) {
            // 次の友達の村までの距離を算出
            llong distance = friends[friendsCount].first - currentPos;
            //printf("K:%lld, distance:%lld\n",K,distance);
            //たどり着くか判定
            if(K >= distance){
                // たどり着くなら、そこまで移動して、お金もらう
                currentPos = friends[friendsCount].first;
                K = K - distance + friends[friendsCount].second;
                friendsCount++;
            }
            else{
                // 無理なら、終了
                currentPos = currentPos + K;
                break;
            }
        }else{
            // 次の友達の村がないなら終了
            currentPos = currentPos + K;
            break;
        }
    }
    cout << currentPos << endl;

    return 0;
}