/*【问题描述】

三个工人从8点开始上班。第一个工人在300秒(从8点开始)开始干活，一直到1000秒。第二个工人在800秒开始，在 1300秒结束。第三个工人在1500秒开始，在2100秒结束。期间最长的至少有一个工人在干活的连续时间LWT为1000秒(从300秒到1300秒)，而最长的无人干活的连续时间LRT(从第一个工人开始一直到最后一个工人结束)为200秒(从1300秒到1500秒)。

你的任务是编一个程序，读入一个有N个工人(1 <= N <= 5000)干活的工作时间列表，计算以下两点(均以秒为单位):

最长至少有一人在工作的时间段LWT。

最长的无人工作的时间段LRT。（从有人工作开始算起）

【输入形式】

第1行:一个整数N。

第2至第N+1行:每行两个小于1000000的非负整数，表示一个工人的开始时刻与结束时刻。

【输出形式】

一行，两个整数，即题目所要求的两个答案LWT与LRT。

【样例输入】

3

300 1000

800 1300

1500 2100
 【样例输出】

1000 200
*/ 


#include<stdio.h>
//采用堆栈的方法，只要有人进场，top++，如果top==-1，说明此时已无人工作，进行比较修改LWT和LRT的值，直到最晚退场的一个人退场，整个遍历结束
  void  sort(int K[],int n)
  {     int i, j, d;
         int  temp;
         for(i=0;i<n;i++){
              d=i;
              for(j=i+1;j<n;j++)
                    if(K[j]<K[d])
                         d=j;
              if(d!=i){
                     temp=K[d] ;
                     K[d]=K[i];
                     K[i]=temp;
              }
         }
  }     //选择排序


int main(){
    int n,come[5000],leave[5000],stack[10000],i=0,top=-1,index1=0,index2=0,LWT=0,LRT=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d %d",&come[i],&leave[i]);
    sort(come,n);
    sort(leave,n);
    stack[++top]=come[0];
    index1=1;   //第一个人先进栈
    while(1){
        if((index1<n)&&(come[index1]<=leave[index2])){      //如果还有人没有开始工作，并且比离场的人先入场，就进栈
            stack[++top]=come[index1];
            index1++;
        }
        else{           //else 先有人离开工作，即先退栈
            top--;
            index2++;
        }
        if(top==-1){    //栈空，说明此时无人再工作，就开始比较
            if((leave[index2-1]-stack[0])>LWT)	//stack[0]记录的是这一个工作段第一个开始工作的人 
				LWT=leave[index2-1]-stack[0];
            if(((come[index1]-leave[index2-1])>LRT)&&(index2!=n))	//leave[index2-1]记录的是这个工作段最后一个离开的人的时间 index2=n时表示最后一个人已经走了，come[index1]值已经不对了，LRT当然也不会再发生改变 
				LRT=come[index1]-leave[index2-1];
        }
        if(index2==n)break; //最后一个人离开工作，整个程序结束
    }
    printf("%d %d",LWT,LRT);
return 0;
}
