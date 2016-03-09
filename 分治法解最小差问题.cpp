#include <iostream>
using namespace  std ;

//Using 'Divide and Conquer' method
//First, sort the array with quick sort method (O(nlgn))
//then compare the two neibour items (O(n))
//succeed

//quick_sort 
void swap(int& a,int& b){           
    int temp;
    temp =a;
    a=b;
    b=temp;
}

void quick_sort(int *array,int s,int t)  
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
                            swap(array[i],array[j]);  		/*swapK[i] and K[j]*/
                     else
                            break;
               }
               swap(array[s],array[j]);      			/*swapK[s] and K[j]*/
               quick_sort(array,s,j-1);      		 /*sort part1 */
               quick_sort(array,j+1,t);     		  /* sort part2*/
       }
}

// func to find d:
int find_d(int* a , int n){		//the array must be sorted
	int d ;
	d = a[1] - a[0] ;
	for(int i = 2; i < n ; i++){
		if((a[i] - a[i-1]) < d)
			d = a[i] - a[i-1] ;
	}
	return d ;
}
int main(){
	int* a;
	int n;
	cout << "Please input the size of the array:\n" ;
	cin >> n ;
	a=new int[n] ;
	cout << "Please input the item one by one:\n" ;
	for(int i=0; i < n ; i++)
		cin >> a[i] ;
	quick_sort(a , 0 , n-1) ;
	cout << "After quick_sort, the array is :"<< endl;
	for(int i=0; i < n ; i++)
		cout << a[i] << ' ';
	cout << "The value of d is:  " << find_d(a,n) <<endl ;
	delete[] a;
	return 0;
}
