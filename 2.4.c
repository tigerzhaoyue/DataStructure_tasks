#include <stdio.h>
#include <stdlib.h>
/*������������
 ����һ�������ʽ�а����������ţ�Բ���š������͡������������š�[���͡�]���������š�{���͡�}�������������ſɰ������Ƕ��ʹ�ã��Ա�д�����ж�����ı��ʽ�����������Ƿ���ȷ��Գ��֡���ƥ�䣬�򷵻�1�����򷵻�0��

��������ʽ��
 �����ŵ��������ʽ

�������ʽ��
 �����ʽ�е�������ȷ��ԣ������1���������0��

���������롿
 3+(44*[5-{6*[7*(45-10)]}])

�����������
 1

������˵����
 �ж������Ƿ�ƥ���漰����������⣬һ�Ƕ��������ŵĳ��ִ������ж������ǶԲ�ͬ���ŵĳ��ִ�����ж���

 */
char stak[100];
int top=-1;

void push(char a){
    top++;
    stak[top]=a;
}

void del(char a){
    a=NULL;
    top--;
}


int main()
{
    char ch;
    int rightwrong=0;
    while((ch=getchar())!='\n'){
        if(ch=='('||ch=='['||ch=='{')
            push(ch);
        else if(ch==')'&&top!=-1){
            if(stak[top]=='(')
               del(stak[top]);
            else
                break;
        }
        else if(ch==']'&&top!=-1){
            if(stak[top]=='[')
               del(stak[top]);
            else
                break;
        }
        else if(ch=='}'&&top!=-1){
            if(stak[top]=='{')
               del(stak[top]);
            else
                break;
        }
        else if((ch==')'||ch==']'||ch=='}')&&top==-1)
            rightwrong=1;
    }
    if(top==-1&&rightwrong==0)
        putchar('1');
    else
        putchar('0');
    return 0;
}
