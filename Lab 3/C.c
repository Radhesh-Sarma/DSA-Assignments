#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#include<math.h>
#define int long long
#define MOD 998244353
int factorial[6001];
int absolute(int a)
{
	if(a < 0) return -1*a;
	return a;
}
int modexp(int x, int y)
{
	int mod = MOD;
    int res = 1;
    x = (x % mod + mod) % mod;
    while(y)
    {
        if(y & 1)
            res = (res*x) % mod;
        y >>= 1;
        x = (x*x) % mod;
    }
    return res; 
}

int modInverse(int x)
{
	return modexp(x,MOD-2)%MOD;
}
int32_t main()
{

	factorial[0] = factorial[1] = 1;
	for(int i = 2;  i<=6000;i++)
	{
		factorial[i] = ((factorial[i-1]%MOD)*(i%MOD))%MOD;
	}

	int x1,y1,z1,x2,y2,z2;

	scanf("%lld %lld %lld",&x1,&y1,&z1);
	scanf("%lld %lld %lld",&x2,&y2,&z2);


	int x = absolute(x1-x2);
	int y = absolute(y1-y2);
	int z = absolute(z1-z2);

	int n = x + y + z;


	int ans = (factorial[n]%MOD);

	ans = (ans%MOD * (modInverse(factorial[x]%MOD)%MOD)%MOD);
	ans = (ans%MOD * (modInverse(factorial[y]%MOD)%MOD)%MOD);
	ans = (ans%MOD * (modInverse(factorial[z]%MOD)%MOD)%MOD);

	printf("%lld",ans);


	return 0;
}


