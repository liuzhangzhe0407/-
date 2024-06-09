#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//—°‘Ò≈≈–Ú 
void Swap1(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void SelectSort1(int* a, int n)
{
	int begin = 0, end = n - 1;
 
	while (begin < end)
	{
		int mini = begin, maxi = begin;
		for (int i = begin; i <= end; i++)
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}
		Swap1(&a[begin], &a[mini]);
		if (begin == maxi)
		{
			maxi = mini;
		}
		Swap1(&a[end], &a[maxi]);
		begin++;
		end--;
	}
}
int main(){
	int n=100000,a[n],i,endtime,begintime;
    srand(time(0));
    for(i=0;i<n;i++){
    	a[i]=rand();
	}
  begintime=clock();
	SelectSort1(a,n);
  endtime=clock();
		for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
  printf("\n\nRunning Time£∫%dms\n", endtime-begintime);
} 
