#include<stdio.h>
int fun(int x[],int low,int high){//6 4 2 3 7 6 9 8
	int pivoti=x[low];//6
	int i=low;//0
	int j=high;
	while(i<j){
		while(x[i]<=pivoti && i<high){//4
			i++;//1
		}
		while(x[j]>pivoti && j>=low+1){//
			j--;
		}
		if(i<j){
		int temp=x[i];
		x[i]=x[j];
		x[j]=temp;}
	}
	x[low]=x[j];
	x[j]=pivoti;
	return j;
}
void quicksort(int x[],int low,int high){
	if(low>=high) return;
	//int pivoti_index=fun(x,low,high);
	quicksort(x,low,fun(x,low,high)-1);
	quicksort(x,fun(x,low,high)+1,high);
}
int main()
{
	int n,i;
	scanf("%d",&n);
	int x[n];
	for(i=0;i<n;i++)
	scanf("%d",&x[i]);
	quicksort(x,0,n-1);
	for(i=0;i<n;i++)
	printf("%d ",x[i]);
}
