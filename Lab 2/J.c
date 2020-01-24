#include<stdio.h>
#include<stdint.h>
#define int long long
#define N 1000005
int primes[N];
int k = 0,ans = 0;
int32_t main()
{	
	int n;
	scanf("%lld",&n);
	for(int i = 2;  i*i <=n; i++)
		if(n%i == 0)
		{
			while(n%i == 0)n/=i;
			primes[k++] = i;
		}
	primes[k++] = n;
	for(int i = 0; i < k; i++)ans ^= primes[i];

	printf("%lld",ans);
	return 0;
}

