#include <stdio.h>
#include <stdlib.h>
/*【问题描述】
 假设一算术表达式中包括三种括号：圆括号“（”和“）”，方括号“[”和“]”，花括号“{”和“}”，且三种括号可按意次序嵌套使用，试编写程序判定输入的表达式所含的括号是否正确配对出现。若匹配，则返回1，否则返回0。

【输入形式】
 含括号的算数表达式

【输出形式】
 若表达式中的括号正确配对，则输出1。否则，输出0。

【样例输入】
 3+(44*[5-{6*[7*(45-10)]}])

【样例输出】
 1

【样例说明】
 判断括号是否匹配涉及两方面的问题，一是对左右括号的出现次数的判定，二是对不同括号的出现次序的判定。

 */
char stak[100];
int top=-1;

void push(char a){
    top++;
    stak[top]=a;
}

void del(char a){
    a=NULL;
    top--;
}


int main()
{
    char ch;
    int rightwrong=0;
    while((ch=getchar())!='\n'){
        if(ch=='('||ch=='['||ch=='{')
            push(ch);
        else if(ch==')'&&top!=-1){
            if(stak[top]=='(')
               del(stak[top]);
            else
                break;
        }
        else if(ch==']'&&top!=-1){
            if(stak[top]=='[')
               del(stak[top]);
            else
                break;
        }
        else if(ch=='}'&&top!=-1){
            if(stak[top]=='{')
               del(stak[top]);
            else
                break;
        }
        else if((ch==')'||ch==']'||ch=='}')&&top==-1)
            rightwrong=1;
    }
    if(top==-1&&rightwrong==0)
        putchar('1');
    else
        putchar('0');
    return 0;
}
