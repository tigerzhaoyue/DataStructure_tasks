#include <stdio.h>
#include <stdlib.h>

void findmin_in_heap(int *array,int size){          //find the minimum,and put it to the top of the heap
    int j,parent,child,temp;
    for(j=size-1;j>0;j--){                          //loop from the last item to the second item (the first(array(0)) is prepared for the min_item)
        parent=j/2;
        child=j;
        if(j<size-1&&array[j]>array[j+1]){          //find the min_item of their parent
            child++;
        }
        if(array[child]<array[parent]){             //swap the parent and the min_child
            temp=array[child];
            array[child]=array[parent];
            array[parent]=temp;
        }
    }                                               // now the min_item is on the top of the address
}

void heapsort(int *array,int size){
    int i;
    for(i=0;i<size;i++)                             // loop 10 ¡®Sorting through¡¯
        findmin_in_heap(array+i,size-i);              //every Sorting through,address++,size--
}
int main()
{
    int a[1000],n,j;
    scanf("%d",&n);
    for(j=0;j<n;j++)
        scanf("%d",&a[j]);
    heapsort(a,n);
    for(j=0;j<n;j++)
        printf("%d ",a[j]);
    return 0;
}
