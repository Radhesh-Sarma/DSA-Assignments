#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#define int long long
#define N 505
int adj[N][N];
int vis[N];
 int n, m;
void dfs(int s)
{
	if(vis[s] == 1)return;
	vis[s] = 1;
	for(int i = 1; i <= n; i++)
		if(adj[s][i] == 1)
				if(vis[i] == 0)dfs(i);
}
int32_t main()
{
	 scanf("%lld %lld",&n,&m);
	 for(int i = 1; i <=m; i++)
	 {
	 	int x, y;
	 	scanf("%lld %lld",&x,&y);
	 	adj[x][y] = 1;
	 }
	 int ok = 0;
	 for(int i = 1; i <=n; i++)
	 {
	 	dfs(i);
	 	int k = 0;
	 	for(int j = 1; j <=n; j++)
	 	{
	 		if(vis[j] == 1)k++;
	 		vis[j] = 0;
	 	}
	 	if(k == n)
	 	{
	 		ok = 1;
	 		printf("%lld ",i);
	 	}
	 }
	 if(ok == 0)
	 {
	 	printf("BAD LUCK");
	 }
	return 0;
}


