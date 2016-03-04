#include <stdio.h>
#include <stdlib.h>
/*【问题描述】

已知Q是一个非空队列，S是一个空栈。仅使用少量工作变量以及对队列和栈的基本操作，编写一个算法，将队列Q中的所有元素逆置。


【输入形式】

输入的第一行为队列元素个数，第二行为队列从首至尾的元素


【输出形式】

输出队列的逆置


【样例输入】

3

1 2 3


【样例输出】

3 2 1


【评分标准】

需采用队列与栈的知识，否则不能得分*/
//只要先将队列里的元素先进先出地放入栈中，再将栈里的元素先进后出地放入队列，就实现了队列reverse
int s[1000];
int q[1000];
int top=-1,head=0,tail=0;

/*void out_q(int head,int top){
    top++;
    s[top]=q[head];
    head++;
}

void in_q(int tail,int top){
    tail++;
    q[tail]=s[top];
    top--;
}*/
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&q[i]);
    head=0;     //让q队列第一个元素为head 第i个元素为tail
    tail=i;
    for(i=0;i<n;i++){            //从头出队，进入栈
        top++;
        s[top]=q[head];
        head++;
    }
    head=0;
    tail=-1;     //重新初始化队头队尾的位置
    for(i=0;i<n;i++){           //从栈顶出栈，从尾入队
        tail++;
        q[tail]=s[top];
        top--;
    }
    for(i=0;i<n;i++)
        printf("%d ",q[i]);
    return 0;
}
