#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int A[100];
int N;

void printArray(){
    printf("%d",A[0]);
    for(int i = 1; i < N; i++) {
        printf(" %d",A[i]);
    }
    printf("\n");
}

int solve(){
    int count = 0;
    int flag = 1;
    int i = 0;
    while(flag) {
        flag = 0;
        for(int j = N-1; j >= i + 1; j --) {
            if(A[j] < A[j-1]) {
                int tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                count++;
                flag = 1;
            }
        }
        i++;
    }
    return count;
}

int main()
{
    // 整数の入力
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    printArray();
    int result = solve();
    printArray();
    cout << result << endl;
    return 0;
}


