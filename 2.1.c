#include <stdio.h>
#include <stdlib.h>
/*������������
 ����һ����׺���ʽ�����ʽ����+��-��*��/���������Լ������������ʽ�е���������Ϊ��д����ĸ��ʵ��һ���㷨���õ���Ӧ�ĺ�׺���ʽ��

��������ʽ��
 һ��ʽ�ӵ���׺���ʽ����#����

�������ʽ��
 ��Ӧ�ĺ�׺���ʽ

���������롿
 A*(B-C)/D+E#

�����������
 ABC�C*D/E+

�����ֱ�׼��
 �����ڳ�����д����Ҫ��ע�ͣ��������û�б�Ҫ��ע�ͣ�������۷�*/
char stak[100];             //ȫ�ֱ���
int top=-1;


int compare(char old,char now){     //�Ƚ����ȼ����������ж��Ƿ��ջ����Ҫָ��
    if (now=='*'||now=='/'){
        if(old=='*'||old=='/') return 0;
        else if(old=='+'||old=='-'||old=='(') return 1;    //�����ǰ�����˳���������֮ǰ�ĳ˳����ȼ��ͣ��������źͼӼ����ȼ���
    }
    else if(now=='+'||now=='-'){                                //�����ǰ�����Ӽ�������������ţ�������������������ȼ�����
        if(old=='(') return 1;
        else if(old=='+'||old=='-'||old=='*'||old=='/') return 0;
    }
}


int push(char a){                               //�ѵ�ǰԪ������ջ��
    if(top==99)
        return 0;
    else {
        top++;
        stak[top]=a;
        return 1;
    }
}


int pop(char a){                //�ѵ�ǰԪ�ش�ջ��ȡ����stdout
    putchar(a);
    top--;
    return 1;
}

int del(char a){                        //�ѵ�ǰջ��Ԫ��ɾ����main����������ɾ��������
    top--;
    return 1;
}

int main()
{
    char ch[100];
    int i=0;
    scanf("%s",ch);
    for(i=0;ch[i]!='#';i++){
        if(ch[i]>=65&&ch[i]<=90)        //�������ĸֱ�����
            putchar(ch[i]);
        else{
            if(ch[i]=='(')              //compare������û�жԵ�ǰ����������˵������������Ҫ�����г���ǰ������������ʱ������
                push(ch[i]);
            else if(ch[i]==')'){
                while(stak[top]!='(')
                        pop(stak[top]);
                del(stak[top]);
            }
            else{                       //����compare�����������ȼ��Ƚϣ���������Ӧ�Ķ�ջ�Ĳ���
                if(compare(stak[top],ch[i]))
                    push(ch[i]);
                else{
                    while(!compare(stak[top],ch[i]))
                        pop(stak[top]);
                    push(ch[i]);
                }
            }
        }
    }
    while(top!=-1)                      //ע�⣡�����ն���#��ʱ����ջ�ﻹ���������Ҫ��ʣ��������Ҳ��������ʹջΪ�� �����������
        pop(stak[top]);
    return 0;
}
