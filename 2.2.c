#include <stdio.h>
#include <stdlib.h>
/*������������

��֪Q��һ���ǿն��У�S��һ����ջ����ʹ���������������Լ��Զ��к�ջ�Ļ�����������дһ���㷨��������Q�е�����Ԫ�����á�


��������ʽ��

����ĵ�һ��Ϊ����Ԫ�ظ������ڶ���Ϊ���д�����β��Ԫ��


�������ʽ��

������е�����


���������롿

3

1 2 3


�����������

3 2 1


�����ֱ�׼��

����ö�����ջ��֪ʶ�������ܵ÷�*/
//ֻҪ�Ƚ��������Ԫ���Ƚ��ȳ��ط���ջ�У��ٽ�ջ���Ԫ���Ƚ�����ط�����У���ʵ���˶���reverse
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
    head=0;     //��q���е�һ��Ԫ��Ϊhead ��i��Ԫ��Ϊtail
    tail=i;
    for(i=0;i<n;i++){            //��ͷ���ӣ�����ջ
        top++;
        s[top]=q[head];
        head++;
    }
    head=0;
    tail=-1;     //���³�ʼ����ͷ��β��λ��
    for(i=0;i<n;i++){           //��ջ����ջ����β���
        tail++;
        q[tail]=s[top];
        top--;
    }
    for(i=0;i<n;i++)
        printf("%d ",q[i]);
    return 0;
}
