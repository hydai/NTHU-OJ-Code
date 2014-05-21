#include <stdio.h>
#include <stdlib.h>

void MergeSort(int a[],int n);
void Merge(int a[],int left[],int right[],int x,int y);

int main(void)
{
	/*輸入資料個數*/
	int n;
	scanf("%d",&n);

	/*輸入欲排序資料*/
	int a[n],i;
	for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    /*MergeSort*/
    MergeSort(a,n);

    /*輸出*/
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");

    return 0;
}

void MergeSort(int a[],int n)
{
	if(n<=1) return;

	int x,y,i,left[n/2],right[n/2];
	x = n/2;
	y = n-x;

	for(i=0;i<x;i++) left[i]=a[i];
	for(i=0;i<y;i++) right[i]=a[x+i];

	MergeSort(left,x);
	MergeSort(right,y);
	Merge(a,left,right,x,y);
}

void Merge(int a[],int left[],int right[],int x,int y)
{
	int i=0,j=0,k=0;

	while(i<x && j<y)
	{
		if(left[i] < right[j])
            a[k]=left[i++];
		else
            a[k]=right[j++];
		k++;
	}

	while(i<x) a[k++]=left[i++];
	while(j<y) a[k++]=right[j++];
}
