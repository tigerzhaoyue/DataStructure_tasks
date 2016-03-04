#include<stdio.h>
#include<string.h>
//树的层次遍历采取队列的方式遍历，在此不用创建树。
/*【问题描述】
 给定一颗二叉树，要求从下至上按层遍历二叉树，每层的访问顺序是从左到右，每一层单独输出一行。

【输入形式】
 广义表表示的二叉树，结点元素类型为整型，且都大于0，例如：1( 2( 3 ( 4, 5 ) ), 6( 7, 8( 9, 10 ) ) )

【输出形式】
 从下至上，打印每一层的结点元素值，元素间以空格隔开。每层的访问顺序是从左到右，每一层单独输出一行。

【样例输入】
 1(2(3(4,5)),6(7,8(9,10)))，字符串内没有空格

【样例输出】
 4 5 9 10
 3 7 8
 2 6
 1

【样例说明】

【评分标准】
 本题目主要考察两个知识点：
 1.创建二叉树存储结构
 2.按层次遍历二叉树的算法*/

int main(){
    int floor=0,a[30][30],i,len,j,num,now,basic;
    for(i=0;i<30;i++)
        for(j=0;j<30;j++)
            a[i][j]=0;
    char s[1000];
    scanf("%s",s);
    len=strlen(s);
    i=0;
    while(i<len){
        if(s[i]>='0'&&s[i]<='9'){
            j=i;
            num=0;
            a[floor][0]++;
            now=a[floor][0];   //用a[floor][0]记录该层的数字个数待会作为输出换行控制变量
            while(s[j]>='0'&&s[j]<='9'){
                num=num*10+s[j]-48;
                j++;
            }
            a[floor][now]=num;
            i=j;
        }
        else if(s[i]=='('){
            floor++;
            i++;
        }
        else if(s[i]==')'){
            floor--;
            i++;
        }
        else
            i++;

    }
    for(i=0;a[i][0]!=0;i++);
    basic=i-1;
    for(i=basic;i>=0;i--){
        for(j=1;j<a[i][0];j++)
            printf("%d ",a[i][j]);
        printf("%d\n",a[i][j]);
    }
return 0;
}
