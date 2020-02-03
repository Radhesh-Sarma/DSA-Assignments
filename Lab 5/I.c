#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#define int long long
#define N 3000006
int arr[N];
int ans1 = -100000000000;
int ans2 =  100000000000;
int absolute(int x)
{
	if(x < 0) return -1*x;
	return x;
}

int binarysearch(int low,int high,int x)
{
	while(low <= high)
	{
		int mid = low + (high-low)/2;
		if(arr[mid] == x)
		{
			return mid;
		}
		if(arr[mid] < x)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return -1;
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
int32_t main()
{	

	int n;
	scanf("%lld",&n);


	int ok = 0;

	for(int i = 0; i < n; i++)
	{
		scanf("%lld",&arr[i]);
	}


	mergesort(arr,0,n-1);


	int k;
	scanf("%lld",&k);
	for(int i = 0; i <= n-1; i++)
	{
		int a = binarysearch(0,n-1,k-arr[i]);


		if(a == -1)continue;

		if(a == i)
		{
			if(a == 0 && arr[a+1] != arr[a])
			{
				continue;
			}
			if(a == n-1 && arr[a-1] != arr[a])
			{
				continue;
			}
			if(arr[a] != arr[a-1] && arr[a] != arr[a+1])continue;

		}
		ok = 1;

		if(absolute(ans2 - ans1) > absolute(arr[a]-arr[i]))
			{
				ans1 = i;
				ans2 = a;
			}
	}

	if(ok == 0)
	{
		printf("NO");
		return 0;
	}

	printf("YES\n");
	printf("%lld %lld",arr[ans1],arr[ans2]);




	return 0;
}

