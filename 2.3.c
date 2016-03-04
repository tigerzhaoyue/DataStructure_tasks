#include <stdio.h>
#include <stdlib.h>
#include<string.h>
/*【问题描述】输入一行字符串，内有数字和非数字字符及空格等，例如，ak123x--456 17960?302gef4563，将其中连续的数字作为一个整体，依次存放到一维数组ａ中，例如123 放入ａ[０]，456放入ａ[１]，17960放入a[2]… … ，如果数字前有负号，则将其视为负数。编程分离字符串中的数字并输出，数字之间用空格分开。
【输入形式】一行包含数字、非数字字符（包括空格）的字符串
【输出形式】输出字符串中所含有的数字，数字之间用空格分开
【样例输入】ak123x--456 17960?302gef4563
【样例输出】123 -456 17960 302 4563
*/
int main()
{
    char s[1000];
    int head=-1,tail=-1,flag[100],num[100],n=0,i=0;
    gets(s);
    tail=strlen(s)-1;
    for(i=0;i<100;i++)
        num[i]=flag[i]=0;
    while(head!=tail){
        if(s[head+1]>='0'&&s[head+1]<='9'){
            if(head>=0&&s[head]=='-')
                flag[n]=1;
            num[n]=num[n]*10+s[head+1]-'0';
        }
        if(head>=0&&(s[head]>='0'&&s[head]<='9')&&(!(s[head+1]>='0'&&s[head+1]<='9')))
            n++;
        head++;
    }
    for(i=0;i<=n;i++){
       if(num[i]!=0){
        if(flag[i]==1)
            printf("-%d ",num[i]);
        else
            printf("%d ",num[i]);
    }}
    return 0;
}
