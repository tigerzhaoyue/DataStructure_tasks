
/* 
【问题描述】一个台阶总共有n级，如果一次可以跳1级，也可以跳2级。求总共有多少总跳法，并分析算法的时间复杂度，例如
 n 为1 时只有一种跳法
 n 为2 时只有两种跳法
 【输入形式】输入一个整数n
 【输出形式】n级的跳法数，整数m
 【样例输入】

6
 【样例输出】

13
 */ 


#include<stdio.h>
//一层台阶一种跳法，两层台阶两种跳法，三层台阶有3种跳法，这三种跳法是1-1-1，1-2，2-1
//那么可以看到，三层台阶时，如果第一步为1，那后面就是两层台阶的跳法
//如果第一步为2，那就是1层台阶的跳法
//很自然地想到用数学归纳的方法来解决问题
//f(n)=f(n-1)+f(n-2);
//！！！！！求这个斐波那契数列，为了降低其时间复杂度，可以采用线性代数中矩阵的知识，！！！！
//这样的迭代数列可以通过右乘（1，1，1，0）矩阵来实现
//即：（fn,fn-1,fn-1,fn-2）*(1,1,1,0)=(fn+fn-1,fn,fn,fn-1)=(fn+1,fn,fn.fn-1)
//即(fn,fn-1,fn-1,fn-2)=(1,1,1,0)^n
//再在乘方函数每次除2乘，那么最终时间复杂度可以降为logn
//logn logn logn logn logn logn logn logn logn logn logn
struct matrix{
    int x1;
    int x2;
    int y1;
    int y2;
};
struct matrix multmatrix(struct matrix matrix1,struct matrix matrix2){  //定义矩阵乘
   struct matrix result;
   result.x1=matrix1.x1*matrix2.x1+matrix1.x2*matrix2.y1;
   result.x2=matrix1.x1*matrix2.x2+matrix1.x2*matrix2.y2;
   result.y1=matrix1.y1*matrix2.x1+matrix1.y2*matrix2.y1;
   result.y2=matrix1.y1*matrix2.x2+matrix1.y2*matrix2.y2;
	return result;
}
struct matrix f(int n){ //矩阵乘方函数
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
