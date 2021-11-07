#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    // 整数の入力
    int N;
    cin >> N;

    long long R[200000];
    for(int i = 0; i < N; i++) {
        cin >> R[i];
    }

    long long maxV = -20000000000000;
    long long buy = R[0];
    for(int i = 1; i < N; i++) {
        maxV = max(maxV, R[i]-buy);
        buy = min(buy,R[i]);
    }
    
    cout << maxV << endl;

    return 0;
}
