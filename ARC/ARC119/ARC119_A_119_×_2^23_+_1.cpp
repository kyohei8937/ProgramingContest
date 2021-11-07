#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;
// タイプ定義
typedef long long llong;
// マクロ
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(llong i=llong(a);i<llong(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
 
llong N;
 
int main()
{
   cin >> N;
 
   llong b = 0;
   while(true) {
      if(pow(2,b)>N){
         b--;
         break;
      }
      b++;
   }
 
   llong minSum = 9223372036854775807;
   while(b >= 0) {
      llong a = N / (llong)pow(2,b);
      llong c = N % (llong)pow(2,b);
      //printf("a:%lld,b:%lld,c:%lld,sum:%lld\n",a,b,c,a+b+c);
      if(a+b+c < minSum) {
         minSum = a+b+c;
      }
      b--;
   }
   cout << minSum << endl;
   return 0;
}
