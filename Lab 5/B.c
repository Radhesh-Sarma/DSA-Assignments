#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#define int long long
#define N 1005
#define mod 1000000007

int isbitset(int n,int i)
{
	return ((n) & (1 << i));
}
int32_t main()
{	
	int n;
	scanf("%lld",&n);
	int arr[n];

	for(int i = 0; i < n; i++)
	{
		scanf("%lld",&arr[i]);
	}

	int ans = 0;

	for(int i = 0; i <32; i++)
	{
			int ans1 = 0;

		for(int j = 0; j < n; j++)
		{
			if(isbitset(arr[j],i))
			{
					ans1 = (ans1 + 1)%mod;
			}
		}

		ans1%=mod;

		ans += (2*(((ans1%mod)*((n-ans1)%mod))%mod))%mod;
	}
	printf("%lld",ans);
	return 0;
}

