#include <stdio.h>
#include<stdlib.h>
#include<string.h>
/*������������
 ��֪һ��������������������кͺ���������У����������ǰ��������С�

��������ʽ��
 һ����������������� ��������������У��м��ÿո�ֿ������������н�����Сд��ĸ,��û���ظ�����ĸ

�������ʽ��
 һ������ǰ���������

���������롿
 dbeafcg debfgca

�����������
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
    father=*(s+tail) ;                //��¼���ڸô������λ��
    printf("%c",father);
    for(i=0;father!=*(p+i);i++);
    root=i;                 //��¼�ô�β��ĸ�������е�λ��
    for(i=0,j=0;i<root;i++,j++)     //�����´�
        ls[j]=*(s+i);
    for(i=root,j=0;i<tail;i++,j++)
        rs[j]=*(s+i);
    for(i=0,j=0;i<root;i++,j++)
        lz[j]=*(p+i);
    for(i=root+1,j=0;i<=tail;i++,j++)
        rz[j]=*(p+i);
    if(ls[0]!=NULL)
        f(ls,lz);   //�ݹ����
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
