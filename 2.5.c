#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*������������
 ���һ���򵥵ļ�������һ���Խ����е������������룬�ȼ���ĺ����롣��������һ�����֣���ʾ����������ܸ���������������룬ÿ�б�ʾһ�����������������������Ͳ������������е����뼰�����Ϊ�����������������ֻ��Add��Sub��Mul�����ӷ����������˷����֡�

��������ʽ��
 ���У�����������ܸ���
 ������У�ÿ�����������������������Ͳ�����

�������ʽ��
 ���������

���������롿
 4
 Add 1
 Sub 2
 Mul 4
 Sub 4 5

�����������
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
