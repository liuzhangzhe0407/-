#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main() {//ð�����������������������ϵ�ÿ�������ν��бȽϣ�
	int n=100000,Bubble[n],begintime,endtime;
	int Temp,i,j;
	srand(time(0));
	for(i=0;i<n;i++){
		Bubble[i]=rand();
	}
	begintime=clock();
	for(j=0;j<n;j++){
		for(i=0;i<n;i++)
		{
	if(Bubble[i]>Bubble[i+1])
	{Temp=Bubble[i+1];
		Bubble[i+1]=Bubble[i];
		Bubble[i]=Temp;}
	   }
}
endtime = clock();
	for(i=0;i<n;i++){
		printf("%d ",Bubble[i]);
	}
printf("\n\nRunning Time��%dms\n", endtime-begintime);
	return 0;
 } 

