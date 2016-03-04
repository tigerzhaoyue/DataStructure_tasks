#include <stdio.h>
#include<stdlib.h>
#include<string.h>
/*【问题描述】
 已知一个二叉树的中序遍历序列和后序遍历序列，求这棵树的前序遍历序列。

【输入形式】
 一个树的中序遍历序列 该树后序遍历序列，中间用空格分开。输入序列中仅含有小写字母,且没有重复的字母

【输出形式】
 一个树的前序遍历序列

【样例输入】
 dbeafcg debfgca

【样例输出】
 abdecfg*/

void f(char *s,char *p){
    int tail,i,j,root;
    char ls[100],rs[100],lz[100],rz[100],father;
    for(i=0;i<100;i++){
        ls[i]=NULL;
        rs[i]=NULL;
        lz[i]=NULL;
        rz[i]=NULL;
    }
    tail=strlen(s)-1;
    father=*(s+tail) ;                //记录现在该串的最后位置
    printf("%c",father);
    for(i=0;father!=*(p+i);i++);
    root=i;                 //记录该串尾字母在中序中的位置
    for(i=0,j=0;i<root;i++,j++)     //构造新串
        ls[j]=*(s+i);
    for(i=root,j=0;i<tail;i++,j++)
        rs[j]=*(s+i);
    for(i=0,j=0;i<root;i++,j++)
        lz[j]=*(p+i);
    for(i=root+1,j=0;i<=tail;i++,j++)
        rz[j]=*(p+i);
    if(ls[0]!=NULL)
        f(ls,lz);   //递归调用
    if(rz[0]!=NULL)
        f(rs,rz);
}
int main() {
    char zhong[100],hou[100];
    scanf("%s",zhong);
    scanf("%s",hou);
    f(hou,zhong);
    return 0;
}
