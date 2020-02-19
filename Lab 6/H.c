#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#define int long long

int32_t main()
{	
	int n;
	scanf("%lld",&n);

	int arr[n];
	int stack[n];
	int st=-1;

	for(int i=0;i<n;i++)
	{
		scanf("%lld",&(arr[i]));
	}
	int max=0;
	int area;

	int i=0;
	while(i<n)
	{
		if(st==-1 || arr[i]>=arr[stack[st]])
		{
			stack[++st] = i;
			i++;
		}
		else
		{	
			if(st!=0)
			{
				area = arr[stack[st]]*(i-stack[st-1]-1);
			}
			else
			{
				area = arr[stack[st]]*i;
			}
			
			if(area>max)
			{
				max = area;
			}
			st--;
		}
	}

	while(st!=-1)
	{
		area = arr[stack[st]]*(i-stack[st-1]-1);
		if(area>max)
		{
			max = area;
		}
		st--;
	}

	printf("%lld\n",max);

	return 0;
}
