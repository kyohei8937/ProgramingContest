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

llong N;
vector<pair<llong,string>> mountainArray;

int main()
{
    char s[256];
    memset(s,'0',256);
    fgets(s,256,stdin);
    //cout << s << endl;
    vector<int> must;
    vector<int> ng;
    rep(i,10) {
        if(s[i] == 'o'){
            //cout << "must:" << i << endl;
            must.push_back(i);
        }else if(s[i] == 'x'){
            //cout << "ng:" << i << endl;
            ng.push_back(i);
        }
    }
    int a[4];
    int count = 0;
    for(int i =0; i <= 9999; i++) {
        a[0] = i / 1000;
        a[1] = (i % 1000)/ 100;
        a[2] = (i % 100) / 10;
        a[3] = i % 10;
        bool isOK = true;
        // ngが一つも含まれていないことのチェック
        rep(j,ng.size()){
            if(ng[j] == a[0] || ng[j] == a[1] || ng[j] == a[2] || ng[j] == a[3]){
                isOK = false;
                break;
            }
        }
        if(!isOK) {
            //cout << a[0] << a[1] << a[2] << a[3] << "is not OK1" << endl;
            continue;
        }

        // mustがすべて含まれていることのチェック
        rep(j,must.size()){
            if(must[j] != a[0] && must[j] != a[1] && must[j] != a[2] && must[j] != a[3]){
                isOK = false;
                break;
            }
        }
        if(!isOK) {
            //cout << a[0] << a[1] << a[2] << a[3] << "is not OK2" << endl;
            continue;
        }
        count++;
    }
    cout << count << endl;
    return 0;
}