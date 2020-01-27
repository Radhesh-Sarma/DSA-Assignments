#include<stdio.h>
#include<stdint.h>
#define int long long

 int arr[505][505];
  int vis[505][505];

  int n, m;
  //Flood Fill
  void dfs(int x,int y)
  {
    if(x < 1 || x > n || y < 1 || y > m)
      {
        return;
      }
      if(!arr[x][y])
      {
        return;
      }
    if(vis[x][y])
      {
        return;
      }	
    vis[x][y] = 1;


    dfs(x-1,y);
    dfs(x+1,y);
    dfs(x,y+1);
    dfs(x,y-1);
  }
  int32_t main()
  {         
    scanf("%lld %lld",&n,&m);

    for(int i = 1; i <= n; i++)
    {
      for(int j = 1; j <= m; j++)
      {
        scanf("%lld",&arr[i][j]);
      }
    }

    int p1,q1,p2,q2;
    scanf("%lld %lld",&p1,&q1);
    scanf("%lld %lld",&p2,&q2);


    if(arr[p1+1][q1+1] == 0)
    {
      printf("NO");
      return 0;
    }

    dfs(p1+1,q1+1);
    if(vis[p2+1][q2+1])
    {
      printf("YES");
    }
    else
    {
      printf("NO");
    }
  return 0; 
}
