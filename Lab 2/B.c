#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#define int long long
#define N 1000005
#define INF 1000000000000
int dp[N];
int min(int a,int b)
{
	if(a <= b)return a;
	return b;
}
int32_t main()
{
int a,b,c,d,e,f;
scanf("%lld %lld %lld %lld %lld %lld",&a,&b,&c,&d,&e,&f);
dp[0] = 0;
for(int i = 1; i < N; i++)dp[i] = INF;
for(int i = 0; i < N; i++)
{
	if(a*i+b < N)dp[a*i+b] = min(dp[a*i+b],dp[i]+1);
	if(c*i+d < N)dp[c*i+d] = min(dp[c*i+d],dp[i]+1);
	if(e*i+f < N)dp[e*i+f] = min(dp[e*i+f],dp[i]+1);
}
int q;
scanf("%lld",&q);
while(q--)
{
	int x;
	scanf("%lld",&x);
	if(dp[x] == INF)dp[x] = -1;
	printf("%lld\n",dp[x]);
}
return 0;
}
