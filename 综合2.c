
/* 
������������һ��̨���ܹ���n�������һ�ο�����1����Ҳ������2�������ܹ��ж������������������㷨��ʱ�临�Ӷȣ�����
 n Ϊ1 ʱֻ��һ������
 n Ϊ2 ʱֻ����������
 ��������ʽ������һ������n
 �������ʽ��n����������������m
 ���������롿

6
 �����������

13
 */ 


#include<stdio.h>
//һ��̨��һ������������̨����������������̨����3��������������������1-1-1��1-2��2-1
//��ô���Կ���������̨��ʱ�������һ��Ϊ1���Ǻ����������̨�׵�����
//�����һ��Ϊ2���Ǿ���1��̨�׵�����
//����Ȼ���뵽����ѧ���ɵķ������������
//f(n)=f(n-1)+f(n-2);
//���������������쳲��������У�Ϊ�˽�����ʱ�临�Ӷȣ����Բ������Դ����о����֪ʶ����������
//�����ĵ������п���ͨ���ҳˣ�1��1��1��0��������ʵ��
//������fn,fn-1,fn-1,fn-2��*(1,1,1,0)=(fn+fn-1,fn,fn,fn-1)=(fn+1,fn,fn.fn-1)
//��(fn,fn-1,fn-1,fn-2)=(1,1,1,0)^n
//���ڳ˷�����ÿ�γ�2�ˣ���ô����ʱ�临�Ӷȿ��Խ�Ϊlogn
//logn logn logn logn logn logn logn logn logn logn logn
struct matrix{
    int x1;
    int x2;
    int y1;
    int y2;
};
struct matrix multmatrix(struct matrix matrix1,struct matrix matrix2){  //��������
   struct matrix result;
   result.x1=matrix1.x1*matrix2.x1+matrix1.x2*matrix2.y1;
   result.x2=matrix1.x1*matrix2.x2+matrix1.x2*matrix2.y2;
   result.y1=matrix1.y1*matrix2.x1+matrix1.y2*matrix2.y1;
   result.y2=matrix1.y1*matrix2.x2+matrix1.y2*matrix2.y2;
	return result;
}
struct matrix f(int n){ //����˷�����
    struct matrix result;
    if(n==0){
        result.x1=1;
        result.x2=1;
        result.y1=1;
        result.y2=1;
        return result;
    }
    else if(n==1){
        result.x1=1;
        result.x2=1;
        result.y1=1;
        result.y2=0;
        return result;
    }
    else{
        if(n%2==0)
            return multmatrix(f(n/2),f(n/2));   //logn logn logn logn logn logn logn logn logn logn logn
        else
            return multmatrix(f(n-1),f(1));
    }
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d",f(n).x1);
return 0;
}
