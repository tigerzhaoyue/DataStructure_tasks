/*��������������дһ�������ж�һ���ַ����Ƿ�Ϊ�����ġ���˳���͵�����һ�����ַ�����Ϊ�����ġ�����
��������ʽ������С��100�������ַ���
�������ʽ����������ַ����ǻ��ģ��������yes��������ַ������ǻ��ģ��������no��
������1���롿abcdcba
������1�����yes

����������2��abcdfsfdsg

������2�����no
������˵��������1�У��ַ���abcdcba�ǻ��ģ���������yes��������2�У�abcdfsfdsg���ǻ��ģ�������"no"
 */
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
struct node *llink;
char m;
struct node *rlink;
}lnode,*linklist;

int main()
{
    char c;
    linklist head=NULL,p=NULL,tail=NULL,before=NULL,lindex=NULL,rindex=NULL;
    while((c=getchar())!='\n'){    //�Իس���ո��˳���ȡ
        p=(linklist)malloc(sizeof(linklist));
        p->m=c;
        if(head==NULL){
            head=p;
            head->llink=NULL;// ͷ����ָ��ָ��
            }
        else{
            before->rlink=p;
            p->llink=before;  //����before�͵�ǰp�ڵ�
        }
        before=p;//�����ڵ�P��Ϊbefore
    }
    tail=p;
    tail->rlink=NULL;
    lindex=head;
    rindex=tail;//�ֱ���������ָ���Ƶ�ͷ��β
    while(lindex->m==rindex->m&&lindex!=tail){
        lindex=lindex->rlink;
        rindex=rindex->llink;//����ָ��ֱ���ǰ ���Ųһ��λ��
    }
    if(lindex==tail)
        printf("yes");
    else
        printf("no");

    return 0;
}
