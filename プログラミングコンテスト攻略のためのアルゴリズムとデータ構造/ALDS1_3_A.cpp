#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
#define MAX_CARD 36

int main()
{
    stack<int> operand_stack;
    char operand_buf[256];
    memset(operand_buf,'\0',256);
    int buf_length = 0;
    char current;
    while(true) {
        scanf("%c",&current);
        if('0' <= current && current <= '9') {
            operand_buf[buf_length] = current;
            buf_length++;
        }else if(current == ' '){
            if(buf_length > 0) {
                operand_stack.push(atoi(operand_buf));
                //cout << "push:" << atoi(operand_buf) << endl; 
                memset(operand_buf,'\0',256);
                buf_length = 0;
            }
        }else if(current == '+' || current == '-' || current == '*'){
            int num2 = operand_stack.top();
            operand_stack.pop();
            int num1 = operand_stack.top();
            operand_stack.pop();
            //cout << "num1:" << num1 << " num2:" << num2 << endl;
            switch(current){
                case '+': 
                    operand_stack.push(num1+num2);
                    break;
                case '-': 
                    operand_stack.push(num1-num2);
                    break;
                case '*': 
                    operand_stack.push(num1*num2);
                    break;
                default:
                    break;
            }
        }else{
            break;
        }
    }
    cout << operand_stack.top() << endl;
    return 0;
}