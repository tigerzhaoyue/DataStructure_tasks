#include <stdio.h>
#include <stdlib.h>
void swap(int *a,int *b){           /*����һ����������*/
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void quick_sort(int *array,int s,int t,int position)    /*position��¼��K�������λ��n-k*/
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
                            swap(array+i,array+j);  /*����K[i]��K[j]��λ��*/
                     else
                            break;
               }
        if(j>position){                     /*��ǰ��ȷ��������λ�ñ�position�󣬼���ǰ��>��K���������ʵ�����Ҷ�����*/
               swap(array+s,array+j);      /*����K[s]��K[j]��λ��*/
               quick_sort(array,s,j-1,position);       /* ��ǰһ�������� */
               quick_sort(array,j+1,t,position);       /* �Ժ�һ�������� */
        }
        if(j<=position){                     /*�����ǰ��ȷ��������λ�ñ�positionС������ǰ��<��K���������ֻ��ѱ�������ǰ�߽��п��ţ���Ϊ���ǲ��������Ѿ��ȵ�K������С������λ����*/
               swap(array+s,array+j);      /*����K[s]��K[j]��λ��*/
               quick_sort(array,j+1,t,position);       /* �Ժ�һ�������� */
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
