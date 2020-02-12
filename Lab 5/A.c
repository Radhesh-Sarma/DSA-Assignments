#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#define int long long
#define N 1505
int n;
int adj[N][N];
int vis[N];
int dist1[N];
int dist2[N];
void dfs(int s,int lvl,int dist[])
{

	if(vis[s])return;
	vis[s] = 1;
	dist[s] = lvl;
	for(int i = 0; i <= n-1; i++)
	{
		if(vis[i] == 0 && adj[s][i] == 1)
		{
			dfs(i,lvl+1,dist);
		}
	}
}

int32_t main()
{	

	scanf("%lld",&n);

	for(int i = 1; i <= n - 1; i++)
	{
		int x, y;
		scanf("%lld %lld",&x,&y);
		adj[x][y] = 1;
		adj[y][x] = 1;
	}


	dfs(0,0,dist1);

	int maxnode = 0;
	int dis;
	for(int i = 0 ; i <= n-1; i++)
	{
		if(dist1[maxnode] <= dist1[i])
		{
			maxnode = i;
			dis = dist1[maxnode];
		}
		vis[i] = 0;
	}
		
		printf("%lld\n",maxnode);

	dfs(maxnode,0,dist2);

	int ans = 0,ansdist = dist2[ans];

	for(int i = 0;i <= n-1; i++)
	{
		if(dist2[ans] < dist2[i])
			{
				ansdist = dist2[i];
				ans = i;
			}
	}

	printf("%lld\n",ansdist);
	printf("%lld %lld",ans,maxnode);

	return 0;
}