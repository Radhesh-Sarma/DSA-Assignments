#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#define int long long
#define N 1005
int parent[N];
int sz[N];
void make_set(int s)
{
	parent[s] = s;
	sz[s] = 1;
}
int getParent(int s)
{
	if(s == parent[s])return s;
	else return parent[s] = getParent(parent[s]);
}
void join(int a,int b)
{
	a = getParent(a);
	b = getParent(b);

	if(a != b)
	{
		if(sz[a] < sz[b])
		{
			int temp = a;
			b = a;
			a = b;
		}
		sz[a] += sz[b];
		parent[b] = a;
	}
}
int32_t main()
{
	    int n,m;
	    scanf("%lld %lld",&n,&m);
	    for(int i = 1; i <= n; i++)make_set(i);
	    for(int i = 1 ; i <= m; i++)
	    {
	    	int x, y;
	    	scanf("%lld %lld",&x,&y);
	    	join(x,y);
	    }
	    int ans = 1;
	    for(int i = 1; i <=n; i++)
	    {
	    	int p = getParent(i);
	    	if(sz[p] > sz[ans])ans = p;
	    }
	   	ans = getParent(ans);
	   	printf("%lld\n",n-sz[ans]+1);
	   	for(int i = 1;i <=n; i++)
	   		if(ans != getParent(i))
	   				printf("%lld ",i);
	return 0;
}


