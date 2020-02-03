#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#define int long long
#define N 1005

int adj[N][N];
int vis[N];
int ans[N];
int anssize = 0;
int n,m;
void dfs(int s)
{
	if(vis[s])return;
	vis[s] = 1;

	for(int i = 1; i <= n; i++)
	{
		if(vis[i] == 0 && adj[s][i] == 1)
		{
			dfs(i);
		}
	}
	ans[anssize++] = s;
}

void toposort()
{
	for(int i = 1; i <=n; i++)
	{
		if(!vis[i])
		{
			dfs(i);
		}
	}

	for(int i = anssize-1; i >=0; i--)
	{
		printf("%lld ",ans[i]);
	}
}
int32_t main()
{	

	scanf("%lld %lld",&n,&m);

	for(int i = 1; i <= m; i++)
	{
		int x,y;
		scanf("%lld %lld",&x,&y);
		if(y !=-1)adj[y][x] = 1;
	}

	toposort();


	return 0;
}

