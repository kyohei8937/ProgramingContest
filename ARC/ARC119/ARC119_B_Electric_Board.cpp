#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <unistd.h>

using namespace std;
// タイプ定義
typedef long long llong;
// マクロ
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(llong i=llong(a);i<llong(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

llong N;
string S,T;

int main()
{
   cin >> N;
   cin >> S >> T;

   int s[500000];
   int t[500000];
   int diff[50000];
   int minSamePoint = 50000;

   int sum = 0;
   int diffCount = 0;
   int minDiffPos = 0;
   bool isFirst = true;
   rep(i,N){
      s[i] = S[i]-'0';
      t[i] = T[i]-'0';
      diff[i] = s[i] - t[i];
      if(diff[i] != 0){
         diffCount++;
         if(isFirst){
            minDiffPos = i;
            isFirst = false;
         }
      }
      sum = sum + diff[i];
   }
   if(sum!=0) {
      cout << "-1" << endl;
      return 0;
   }

   int operateCount = 0;
   while(diffCount != 0) {
      // 入れ替え位置サーチ
      //sleep(1);
      bool isExistDiff = false;
      int nextMinDiffPos = 0;
      int i = minDiffPos+1;
      while(s[minDiffPos] == s[i]){
         if(isExistDiff == false && s[i] != t[i]) {
            nextMinDiffPos = i;
            isExistDiff = true;
         }
         i++;
      }
      // 入れ替え先が不一致なら、入れ替えるけど、差分個数は減らない
      //printf("exchange %d %d next:%d\n",minDiffPos, i,nextMinDiffPos);
      if(s[i] == 0) {
         s[i] = 1;
         s[minDiffPos] = 0;
      }else{
         s[i] = 0;
         s[minDiffPos] = 1;
      }
      if(!isExistDiff){
         minDiffPos = i;
      }else{
         minDiffPos = nextMinDiffPos;
      }
      if(diff[i] != 0){
         diffCount = diffCount - 2;
      }
      rep(j,N)cout << s[j];
      cout << endl;
      operateCount++;
   }
   cout << operateCount << endl;
   return 0;
}