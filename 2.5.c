#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*【问题描述】
 设计一个简单的计算器，一次性将所有的运算命令输入，先计算的后输入。首行输入一个数字，表示运算命令的总个数；其余各行输入，每行表示一个运算命令（包括运算操作符和操作数）。所有的输入及输出都为整数。运算操作符有只有Add、Sub、Mul，即加法、减法、乘法三种。

【输入形式】
 首行：运算命令的总个数
 其余各行：每次运算命令，包括运算操作符和操作数

【输出形式】
 输出计算结果

【样例输入】
 4
 Add 1
 Sub 2
 Mul 4
 Sub 4 5

【样例输出】
 3*/
struct step{
    char s[3];
    int num;
};


int main()
{
    struct step a[100];
    int n,i,start,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%s %d",a[i].s,&a[i].num);
    scanf("%d",&start);
    for(j=i-1;j>=0;j--){
        if(strcmp(a[j].s,"Add")==0)
            start=start+a[j].num;
        else if(strcmp(a[j].s,"Mul")==0)
            start=start*a[j].num;
        else if(strcmp(a[j].s,"Sub")==0)
            start=start-a[j].num;
    }
    printf("%d",start);

    return 0;
}
