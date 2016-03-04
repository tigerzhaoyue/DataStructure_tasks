#include<stdio.h>
/*������������
 ��֪����һ����������������֮���ÿո���ֿ����뽨��һ�����������������������ΪҶ�ڵ㣬����ù��������Ĵ�Ȩ·�����ȡ�

��������ʽ��
 ���������������ĸ�����Ȼ�������Ϊ��������������������������������10��

�������ʽ��
 �����Ӧ��Ȩֵ

���������롿
 5 4 5 6 7 8

�����������
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
