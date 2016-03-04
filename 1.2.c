/*【问题描述】编写一个程序，判断一个字符串是否为“回文”（顺读和倒读都一样的字符串称为“回文”）。
【输入形式】长度小于100的任意字符串
【输出形式】如果输入字符串是回文，则输出“yes”；如果字符串不是回文，则输出“no”
【样例1输入】abcdcba
【样例1输出】yes

【样例输入2】abcdfsfdsg

【样例2输出】no
【样例说明】样例1中，字符串abcdcba是回文，因此输出”yes“；样例2中，abcdfsfdsg不是回文，因此输出"no"
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
    while((c=getchar())!='\n'){    //以回车或空格退出读取
        p=(linklist)malloc(sizeof(linklist));
        p->m=c;
        if(head==NULL){
            head=p;
            head->llink=NULL;// 头部左指针指空
            }
        else{
            before->rlink=p;
            p->llink=before;  //连接before和当前p节点
        }
        before=p;//将现在的P记为before
    }
    tail=p;
    tail->rlink=NULL;
    lindex=head;
    rindex=tail;//分别把两个标记指针移到头和尾
    while(lindex->m==rindex->m&&lindex!=tail){
        lindex=lindex->rlink;
        rindex=rindex->llink;//两端指针分别向前 向后挪一个位置
    }
    if(lindex==tail)
        printf("yes");
    else
        printf("no");

    return 0;
}
