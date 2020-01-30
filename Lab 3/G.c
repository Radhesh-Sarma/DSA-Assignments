#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#define int long long
  #define N 1005
int n,m;
int adj[N][N];
int mainserver;
int ans = 0;
void dfs(int node,int adj2[N][N],int vis[])
{
  if(vis[node])return;
  vis[node] = 1;
  ans++;
  for(int i = 0; i <= n-1; i++)
    if(adj2[node][i] == 1 && vis[i] == 0)dfs(i,adj2,vis);
}
int iscutvertex(int node)
{
  ans = 0;
  int vis[n+1];
  int adj2[N][N];
  for(int i = 0 ; i<=n-1; i++)
  {
    for(int j = 0; j <=n-1;j++)
    {
      adj2[i][j] = adj[i][j];
    }
  }
  for(int i = 0; i <=n-1; i++)
  {
    adj2[i][node] = 0;
    adj2[node][i] = 0;
    vis[i] = 0;
  }
   dfs(mainserver,adj2,vis);
  if(ans >= n-1)return -1;
  return ans;
}
 int32_t main()
  {    
    scanf("%lld %lld",&n,&m);
    for(int i = 1; i <= m; i++)
    {
      int x, y;
      scanf("%lld %lld",&x,&y);
      adj[x][y] = 1;
      adj[y][x] = 1;
    }

    scanf("%lld",&mainserver);
    int ans = 1000000000;
    int ansvertex = -1;
   for(int i = 0 ; i <= n-1; i++)
   {
    if(i != mainserver)
    {
       int a =  iscutvertex(i);
       if(a == -1)continue;
       if(ans > a)
       {
        ans = a;
        ansvertex = i;
       }
    }
   }
   
   if(ansvertex == -1)
   {
      printf("BLACK OUT");
      return 0;
   }
   printf("%lld",ansvertex);
  }
