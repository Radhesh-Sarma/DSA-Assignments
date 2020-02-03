#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#define int long long
int32_t main()
{	

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int n,k;

	scanf("%lld %lld",&n,&k);

	int arr[n];

	for(int i = 0;i < n; i++)arr[i] = 0;


	int j = n-1;

	while(k)
	{
		arr[j--] = k%2;
		k/=2;
	}

	int zeros = 0;

	for(int i = 0; i < n; i++)
	{
		if(!arr[i])zeros++;
	}

	 k = (1 << zeros);



	for(int i = 0;i < k; i++)
	{
		int z = 0;
		int ans[zeros];
		int y = zeros - 1;
		int num = i;
		for(int l = 0; l < zeros; l++)ans[l] = 0;

		while(num)
		{
			ans[y--] = num%2;
			num/=2;
		}

		int idx = 0;

			for(int j = 0; j < n; j++)
			{	
				if(arr[j] == 0)
				{	

					printf("%lld",ans[idx++]);
				}
				else
				{
					printf("1");
				}

			}
			printf("\n");
	}


	return 0;
}

