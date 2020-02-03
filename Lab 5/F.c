#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#define int long long

void merge(int arr[],int start,int mid,int end)
{
	int i = start;
	int j = mid + 1;
	int temp[end-start+1];
	int templen = 0;
	while(i <= mid && j <= end)
	{
		if(arr[i] <= arr[j])temp[templen++] = arr[i++];
		else temp[templen++] = arr[j++];
	}
	while(i <= mid) temp[templen++] = arr[i++];
	while(j <= end) temp[templen++] = arr[j++];

	for(int i = start; i <= end; i++)
	{
		arr[i] = temp[i-start];
	}

}

void mergesort(int arr[],int start,int end)
{
	if(start < end)
	{
		int mid = start + (end-start)/2;
		mergesort(arr,start,mid);
		mergesort(arr,mid+1,end);
		merge(arr,start,mid,end);
	}
}
int32_t main()
{	

    int n;
    scanf("%lld",&n);

    int ans = 1;
    int arr[n];
    int k = 1;
    for(int i = 0; i < n; i++)
    {
    	scanf("%lld",&arr[i]);
    }
    mergesort(arr,0,n-1);
    for(int i = 1; i <= n-1; i++)
    {
    	if(arr[i] != arr[i-1])k++;
  		ans+=k;
    }
    printf("%lld",ans);
	return 0;
}
