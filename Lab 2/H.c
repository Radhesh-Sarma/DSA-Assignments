#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#define int long long
#define N 505
int adj[N][N];
int vis[N];
 int n;
int parent[N];
int lvl[N];
void dfs(int s,int level)
{
	if(vis[s])return;
	vis[s] =1;
	lvl[s] = level;
	for(int i = 1; i <= n; i++)
	{
		if(adj[s][i] == 1 && vis[i] == 0)
		{
			dfs(i,level+1);
		}
	}
}
int32_t main()
{
	scanf("%lld",&n);
	for(int i = 1; i <= n-1; i++)
	{
		int x;
		scanf("%lld",&x);
		adj[x][i] = 1;
	}
	dfs(0,0);
	int k;
	scanf("%lld",&k);
	int ok = 0;
	for(int i =1; i <=n; i++)
	{
		if(lvl[i] == k)
		{
			ok = 1;
			printf("%lld ",i);
		}
	}
	if(ok == 0)
	{
		printf("-1");
	}
	return 0;
}



