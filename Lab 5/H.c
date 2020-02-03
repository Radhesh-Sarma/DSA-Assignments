#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#define int long long
#define N 10005
int n,m;
int arr[N][N];
int binarysearch(int row,int low,int high,int x)
{
	while(low <= high)
	{
		int mid = low + (high-low)/2;
		if(arr[row][mid] == x)return mid;
		if(arr[row][mid] < x)
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
int32_t main()
{	
      scanf("%lld %lld ",&n,&m);

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			scanf("%lld",&arr[i][j]);
		}
	}

	int x;
	scanf("%lld",&x);

	int ok = 0;

	for(int i = 1; i <= n; i++)
	{
		if(x >= arr[i][1] && x <= arr[i][n])
		{
			int y = binarysearch(i,1,n,x);
			if(y != -1)
			{
				ok = 1;
				printf("YES\n");
				printf("%lld %lld",i-1,y-1);
				return 0;
			}
		}
	}

	printf("NO");


	return 0;
}

