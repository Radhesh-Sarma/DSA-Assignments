#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#define int long long
#define N 1000006
int n,k;
int arr[N];
int absolute(int x)
{
	if(x < 0) return -1*x;
	return x;
}
int check(int mid,int x)
{
	if(arr[mid] <= x)return 0;
	return 1;
}
int lowerbound(int low,int high,int x)
{
	while(low <= high)
	{
		int mid = low + (high-low)/2;

		if(check(mid,x))
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return low - 1;
}

void merge(int arr[],int start,int mid,int end)
{
	int i = start;
	int j = mid+1;
	int temp[end-start+1];
	int templen = 0;
	while(i <= mid && j <= end)
	{
		if(arr[i] <= arr[j])temp[templen++] = arr[i++];
		else temp[templen++] = arr[j++];
	}
	while(i <= mid)temp[templen++] = arr[i++];
	while(j <= end)temp[templen++] = arr[j++];

	for(int i = start; i <= end;i++)
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

int nchoose3(int n)
{
	if(n < 3)return 0;
	return (n*(n-1)*(n-2))/6;
}

int32_t main()
{	

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	
	scanf("%lld %lld",&n,&k);

	for(int i = 0; i < n; i++)
	{
		scanf("%lld ",&arr[i]);
	}

	int ans = 0;


	for(int i = 0; i < n; i++)
	{
		int a = lowerbound(0,n-1,k + arr[i]);
		ans += nchoose3(lowerbound(0,n-1,k + arr[i]) - i + 1);
		i = a + 1;
	}

	printf("%lld",ans);

	return 0;
}

