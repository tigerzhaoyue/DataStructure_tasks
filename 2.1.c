#include <stdio.h>
#include <stdlib.h>
/*【问题描述】
 输入一个中缀表达式，表达式中有+、-、*、/四种运算以及（、），表达式中的其他符号为大写的字母。实现一个算法，得到相应的后缀表达式。

【输入形式】
 一个式子的中缀表达式，以#结束

【输出形式】
 相应的后缀表达式

【样例输入】
 A*(B-C)/D+E#

【样例输出】
 ABC–*D/E+

【评分标准】
 请大家在程序中写出必要的注释，如果程序没有必要的注释，将酌情扣分*/
char stak[100];             //全局变量
int top=-1;


int compare(char old,char now){     //比较优先级函数，是判断是否进栈的重要指标
    if (now=='*'||now=='/'){
        if(old=='*'||old=='/') return 0;
        else if(old=='+'||old=='-'||old=='(') return 1;    //如果当前读到乘除，则它比之前的乘除优先级低，比左括号和加减优先级高
    }
    else if(now=='+'||now=='-'){                                //如果当前读到加减，则除了左括号，它比其它的运算符优先级都低
        if(old=='(') return 1;
        else if(old=='+'||old=='-'||old=='*'||old=='/') return 0;
    }
}


int push(char a){                               //把当前元素推入栈顶
    if(top==99)
        return 0;
    else {
        top++;
        stak[top]=a;
        return 1;
    }
}


int pop(char a){                //把当前元素从栈顶取出并stdout
    putchar(a);
    top--;
    return 1;
}

int del(char a){                        //把当前栈顶元素删除，main函数中用于删除左括号
    top--;
    return 1;
}

int main()
{
    char ch[100];
    int i=0;
    scanf("%s",ch);
    for(i=0;ch[i]!='#';i++){
        if(ch[i]>=65&&ch[i]<=90)        //如果是字母直接输出
            putchar(ch[i]);
        else{
            if(ch[i]=='(')              //compare函数中没有对当前读入括号作说明，所以这里要单独列出当前读入左右括号时该怎样
                push(ch[i]);
            else if(ch[i]==')'){
                while(stak[top]!='(')
                        pop(stak[top]);
                del(stak[top]);
            }
            else{                       //调用compare函数进行优先级比较，并做出相应的对栈的操作
                if(compare(stak[top],ch[i]))
                    push(ch[i]);
                else{
                    while(!compare(stak[top],ch[i]))
                        pop(stak[top]);
                    push(ch[i]);
                }
            }
        }
    }
    while(top!=-1)                      //注意！！最终读入#号时可能栈里还有运算符，要把剩余的运算符也相继输出，使栈为空 整个程序结束
        pop(stak[top]);
    return 0;
}
