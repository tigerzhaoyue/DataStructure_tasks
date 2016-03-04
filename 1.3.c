/*在某图形操作系统中，有N个窗口，每个窗口都是一个两边与坐标轴分别平行的矩形区域。窗口的边界上的点也属于该窗口。窗口之间有层次的区别，在多于一个窗口重叠的区域里，只会显示位于顶层的窗口里的内容。
当你点击屏幕上一个点的时候，你就选择了处于被点击位置的最顶层窗口，并且这个窗口就会被移到所有窗口的最顶层，而剩余的窗口的层次顺序不变。如果你点击的位置不属于任何窗口，则系统会忽略你这次点击。
现在我们希望你写一个程序模拟点击窗口的过程。
【输入形式】
输入的第一行有两个正整数，即N和M。（1≤N≤10，1≤M≤10）接下来N行按照从最下层到最顶层的顺序给出N个窗口的位置。每行包含四个非负整数x1,y1,x2,y2，表示该窗口的一对顶点坐标分别为(x1,y1)和(x2,y2)。保证x1<x2，y1<y2。
接下来M行每行包含两个非负整数x,y，表示一次鼠标点击的坐标。题目中涉及到的所有点和矩形的顶点的x,y坐标分别不超过2559和1439。
【输出形式】
输出包括M行，每一行表示一次鼠标点击的结果。如果该次鼠标点击选择了一个窗口，则输出这个窗口的编号（窗口按照输入中的顺序从1编号到N）；如果没有，则输出"IGNORED"（不含双引号）。
【样例输入】
3 4
0 0 4 4
1 1 5 5
2 2 6 6
1 1
0 0
4 4
0 5
【样例输出】
2
1
1
IGNORED
【样例说明】
第一次点击的位置同时属于第1和第2个窗口，但是由于第2个窗口在上面，它被选择并且被置于顶层。
第二次点击的位置只属于第1个窗口，因此该次点击选择了此窗口并将其置于顶层。现在的三个窗口的层次关系与初始状态恰好相反了。第三次点击的位置同时属于三个窗口的范围，但是由于现在第1个窗口处于顶层，它被选择。
最后点击的(0,5)不属于任何窗口。
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
int x1,y1,x2,y2;
int k;//记录是第几个窗口
struct node *link;
}lnode,*linklist;

int main()
{
    int n,m,i,x[10],y[10],a=1;
    linklist p=NULL,tail=NULL,head=NULL,index=NULL,before_index;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){	//build 
        p=(linklist)malloc(sizeof(lnode));
        scanf("%d %d %d %d",&(p->x1),&(p->y1),&(p->x2),&(p->y2));
        p->k=a;
        a++;
        if(tail==NULL){
            tail=p;
            tail->link=NULL;
        }
        else
            p->link=head;
        head=p;
    }
    for(i=0;i<m;i++)
        scanf("%d %d",&x[i],&y[i]);
    for(i=0;i<m;i++){
        index=head;
        before_index=head;
        while(index!=NULL&&(x[i]<index->x1||x[i]>index->x2||y[i]<index->y1||y[i]>index->y2)){	//不在index区域内 
            before_index=index;
            index=index->link;
        }
        if(index==NULL)
            printf("IGNORED\n");
        else if(index==head)	//只输出，不改变窗口次序 
            printf("%d\n",index->k);
        else {
            before_index->link=index->link;
            index->link=head;
            head=index;	//head始终指向最开头元素 
            printf("%d\n",index->k);
        }
    }
    return 0;
}
