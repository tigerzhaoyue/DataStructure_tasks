#include <stdio.h>
#include<string.h>
/*【问题描述】输入一个整数数组，判断该数组是不是某二元查找树的后序遍历的结果。如果是返回true，否则返回false。
【输入形式】输入任意长度的数组，数字之间空格分开
【输出形式】true 或者 false
【样例输入】输入5 7 6 9 11 10 8
【样例输出】true
【样例说明】由于这一整数序列是如下树的后序遍历结果：

         8
       /  \
      6    10
    / \    / \
   5   7   9  11

因此返回true。

【评分标准】暴力求解法不得分。*/
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
