#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()//插入排序 （先按顺序比较，碰到比前一个小的数，二者互换，同时用那个小的数和之前排好的所有的数进行比较，直到碰到比那个小的数还小的） 
{
	int n=100000,Insert[n],begintime,endtime;
    srand(time(0));
	for(int i=0;i<n;i++){
		Insert[i]=rand();
	}
	int Temp=0;
	begintime=clock();
	for(int i=1;i<n;i++){
		Temp=Insert[i];
		if(Insert[i]<Insert[i-1]){
			for(int j=i-1;j>=0&&Temp<Insert[j];j--){
				Insert[j+1]=Insert[j];
				Insert[j]=Temp;
			}
		}
	}
	endtime = clock();
	for(int i=0;i<n;i++){
		printf("%d ",Insert[i]); 
		}
		printf("\n\nRunning Time：%dms\n", endtime-begintime);
	return 0;
}
