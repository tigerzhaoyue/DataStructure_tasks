#include <stdio.h>
#include <stdlib.h>
void swap(int *a,int *b){           /*定义一个交换函数*/
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void quick_sort(int *array,int s,int t)    /*small to big*/
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
               swap(array+s,array+j);      /*交换K[s]与K[j]的位置*/
               quick_sort(array,s,j-1);       /* 对前一部分排序 */
               quick_sort(array,j+1,t);       /* 对后一部分排序 */
       }
}
int main()
{
	int a[10001],i,counter[65536],n;
	char c;
	for(i=0;i<65536;i++)
		counter[i]=0;
	i=0; 
	while(1){
		scanf("%d%c",&a[i],&c);
		counter[a[i]]++;	/*hash*/
		i++;
		if(c=='#')
			break;
	} 
	n=i;	/*how many numbers*/
	quick_sort(a,0,n-1);
	for(i=0;i<n;i++){
		if((i==0)||(a[i]!=a[i-1]))
			printf("%d=%d\n",a[i],counter[a[i]]);
	}
    return 0;
}
