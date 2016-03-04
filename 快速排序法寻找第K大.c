#include <stdio.h>
#include <stdlib.h>
void swap(int *a,int *b){           /*定义一个交换函数*/
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void quick_sort(int *array,int s,int t,int position)    /*position记录第K大的数的位置n-k*/
{     int i,j;
       if(s<t){
              i=s;
              j=t+1;
              while(1){
                     do  i++;
                     while(!(array[s]<=array[i]||i==t));
                     do  j--;
                     while(!(array[s]>=array[j]||j==s));
                     if(i<j)
                            swap(array+i,array+j);  /*交换K[i]与K[j]的位置*/
                     else
                            break;
               }
        if(j>position){                     /*当前趟确定的数的位置比position大，即当前数>第K大的数，就实行左右都快排*/
               swap(array+s,array+j);      /*交换K[s]与K[j]的位置*/
               quick_sort(array,s,j-1,position);       /* 对前一部分排序 */
               quick_sort(array,j+1,t,position);       /* 对后一部分排序 */
        }
        if(j<=position){                     /*如果当前趟确定的数的位置比position小，即当前数<第K大的数，就只需把比他大的那半边进行快排，因为我们并不关心已经比第K大数还小的数的位置了*/
               swap(array+s,array+j);      /*交换K[s]与K[j]的位置*/
               quick_sort(array,j+1,t,position);       /* 对后一部分排序 */
        }
       }
}

int main()
{
    int array[10001],n,k,i;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
        scanf("%d",&array[i]);
    quick_sort(array,0,n-1,n-k);
    printf("%d",array[n-k]);
    return 0;
}
