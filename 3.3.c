#include<stdio.h>
/*【问题描述】
 已知输入一串正整数，正整数之间用空格键分开，请建立一个哈夫曼树，以输入的数字为叶节点，求这棵哈夫曼树的带权路径长度。

【输入形式】
 首先输入正整数的个数，然后接下来为接下来的正整数，正整数个数不超过10个

【输出形式】
 输出相应的权值

【样例输入】
 5 4 5 6 7 8

【样例输出】
 69*/
int huffman(int *s,int n){
    int i,index1,index2,branch,bh,pr,great;
    if(n==1)
        return 0;
    else{
        for(i=0,index1=0;i<n;i++)
            if(*(s+i)<=*(s+index1)) index1=i;
        for(i=0,great=0;i<n;i++)
            if(*(s+i)>*(s+great)) great=i;
        for(i=0,index2=great;i<n;i++)
            if(*(s+i)<=*(s+index2)&&i!=index1) index2=i;
        branch=*(s+index1)+*(s+index2);
        pr=index1<=index2?index1:index2;
        bh=index1>=index2?index1:index2;
        *(s+pr)=branch;
        for(i=bh;i<n-1;i++)
            *(s+i)=*(s+i+1);
        return branch+huffman(s,n-1);
    }
}
int main(){
    int x,i;
    int s[100];
    scanf("%d",&x);
    for(i=0;i<x;i++)
        scanf("%d",&s[i]);
    printf("%d",huffman(s,x));
return 0;
}
