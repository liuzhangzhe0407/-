#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//¹é²¢ÅÅÐò
void Merge(int sourceArr[],int tempArr[], int startIndex, int midIndex, int endIndex){
    int i = startIndex, j=midIndex+1, k = startIndex;
    while(i!=midIndex+1 && j!=endIndex+1) {
        if(sourceArr[i] > sourceArr[j])
            tempArr[k++] = sourceArr[j++];
        else
            tempArr[k++] = sourceArr[i++];
    }
    while(i != midIndex+1)
        tempArr[k++] = sourceArr[i++];
    while(j != endIndex+1)
        tempArr[k++] = sourceArr[j++];
    for(i=startIndex; i<=endIndex; i++)
        sourceArr[i] = tempArr[i];
}
void MergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex) {
    int midIndex;
    if(startIndex < endIndex) {
        midIndex = startIndex + (endIndex-startIndex) / 2;
        MergeSort(sourceArr, tempArr, startIndex, midIndex);
        MergeSort(sourceArr, tempArr, midIndex+1, endIndex);
        Merge(sourceArr, tempArr, startIndex, midIndex, endIndex);
    }
}
int main(int argc, char * argv[]) {
    int n=100000;
    int i,a[n],b[n],begintime,endtime;
    srand(time(0));
    for(i=0;i<n;i++){
    	a[i]=rand();
	}
   begintime=clock();
    MergeSort(a, b, 0, n-1);
   endtime=clock();
    for(i=0; i<n; i++)
        printf("%d ", a[i]);
    printf("\n");
    printf("\n\nRunning Time£º%dms\n", endtime-begintime);
    return 0;
}
