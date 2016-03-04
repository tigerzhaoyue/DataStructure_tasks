
/*【问题描述】输入n个整数，创建一个双向循环链表进行存储。这些整数从第二个开始，递增有序（设a2<a3<...<an） (ai为第i个整数)。试编写程序，创建双向循环链表，依次将输入的整数存储在该链表的各节点中。然后，将第一个结点删除并插入链表中的适当位置，使整个链表递增有序。

【输入形式】先输入整数的个数，再输入整数列。
【输出形式】以整数递增的顺序，依次输出双向循环链表各个节点存储的整数。

【样例输入】5 3 1 2 4 5
【样例输出】1 2 3 4 5

【样例说明】输入数据的第一个数是整数的个数，其后是整数列，该整数列从第二个开始，递增有序，数据间以空格分开。
【评分标准】根据输入的数据创建双向循环链表，并把原来部分有序的链表处理成有序的链表并输出。


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
