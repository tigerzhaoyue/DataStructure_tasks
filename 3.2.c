#include <stdio.h>
#include<string.h>
/*����������������һ���������飬�жϸ������ǲ���ĳ��Ԫ�������ĺ�������Ľ��������Ƿ���true�����򷵻�false��
��������ʽ���������ⳤ�ȵ����飬����֮��ո�ֿ�
�������ʽ��true ���� false
���������롿����5 7 6 9 11 10 8
�����������true
������˵����������һ�����������������ĺ�����������

         8
       /  \
      6    10
    / \    / \
   5   7   9  11

��˷���true��

�����ֱ�׼��������ⷨ���÷֡�*/
int f(int *s,int n){
    int ls[100],rs[100],i,mid,j,lok=1,rok=1;
    for(i=0;i<100;i++)
        ls[i]=rs[i]=0;
    for(i=0;*(s+i)<*(s+n);i++);
    mid=i;
    if(n==0)
        return 1;
    for(i=mid+1;i<=n;i++)
        if(*(s+n)>*(s+i)) {return 0;}
    for(i=0,j=0;i<mid;i++)
        ls[j]=*(s+i);
    for(i=mid+1,j=0;i<=n;i++)
        rs[j]=*(s+i);
    if(ls[0]!=0)
        lok=f(ls,mid-1);
    if(rs[0]!=0)
        rok=f(rs,j);
    if(lok&&rok)
        return 1;
    else
        return 0;
}
int main() {
    char c=' ';
    int s[100],i;
    for(i=0;i<100;i++)
        s[i]=0;
        i=0;
    while(c!='\n'){
        scanf("%d",&s[i]);
        c=getchar();
        i++;
    }
    if(f(s,i-1))
        printf("true");
    else
        printf("false");
    return 0;
}
