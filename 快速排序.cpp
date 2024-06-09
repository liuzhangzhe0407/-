#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int Partition(int a[],int low,int high)//øÏÀŸ≈≈–Ú 
{
	int pivot=a[low];
	while(low<high)
	    {
		while(low<high&&a[high]>=pivot){high--;}
		a[low]=a[high];
		while(low<high&&a[low]<=pivot){low++;}
		a[high]=a[low];
		}
		a[low]=pivot;
		return low;
}
void Quicksort(int *a,int low,int high){
if(low<high){
		int pivotposition=Partition(a,low,high);
		Quicksort(a,low,pivotposition-1);
		Quicksort(a,pivotposition+1,high);
	}	
	}
int main(){
		int n=100000,a[n],i,begintime,endtime;
		srand(time(0));
		for(i=0;i<n;i++){
			a[i]=rand();
		}
	begintime=clock();
	Quicksort(a,0,n-1);
	endtime=clock();
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n\nRunning Time£∫%dms\n", endtime-begintime);
	return 0;
}
