
/*����������������n������������һ��˫��ѭ��������д洢����Щ�����ӵڶ�����ʼ������������a2<a3<...<an�� (aiΪ��i������)���Ա�д���򣬴���˫��ѭ���������ν�����������洢�ڸ�����ĸ��ڵ��С�Ȼ�󣬽���һ�����ɾ�������������е��ʵ�λ�ã�ʹ���������������

��������ʽ�������������ĸ����������������С�
�������ʽ��������������˳���������˫��ѭ����������ڵ�洢��������

���������롿5 3 1 2 4 5
�����������1 2 3 4 5

������˵�����������ݵĵ�һ�����������ĸ���������������У��������дӵڶ�����ʼ�������������ݼ��Կո�ֿ���
�����ֱ�׼��������������ݴ���˫��ѭ����������ԭ��������������������������������


*/
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
struct node *llink;
int m;
struct node *rlink;
}lnode,*linklist;

int main()
{
    int n,i;
    linklist head=NULL,p=NULL,before=NULL,index=NULL,tail=NULL,neck=NULL;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        p=(linklist)malloc(sizeof(lnode));
        scanf("%d",&(p->m));
        if(head==NULL)
            head=p;
        else if(i==n-1){
            before->rlink=p;
            p->llink=before;
            p->rlink=head;
            head->llink=p;
        }
        else{
            before->rlink=p;
            p->llink=before;
        }
        before=p;
    }
    tail=head->llink;
    neck=head->rlink;
    index=neck;
    if(head->m<index->m){
        for(i=0;i<n;i++){
            printf("%d ",head->m);
            head=head->rlink;
        }
    }
    else{
    while((head->m)>(index->m))
        index=index->rlink;
    if (head!=index){
        head->rlink=index;
        head->llink=index->llink;
        index->llink->rlink=head;
        index->llink=head;
        tail->rlink=neck;
        neck->llink=tail;}
    for(i=0;i<n;i++){
            printf("%d ",neck->m);
            neck=neck->rlink;
        }
    }
    return 0;
}
