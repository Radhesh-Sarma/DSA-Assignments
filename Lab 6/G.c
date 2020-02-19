#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>

#define int long long
#define N 1005

int dist[N][N];


int min(int x, int y) {
  return x < y ? x : y;
}
int32_t main()
{ 




  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < N; j++)
    {
      dist[i][j] = 1000000000;
      if(i == j)
        {
          dist[i][j] = 0;
        }
    }
  }


  int n;
  scanf("%lld",&n);

  int arr[n];
  for(int i = 0; i < n; i++)
  {
    arr[i] = 0;
  }
  for(int i = 1; i <= n - 1; i++)
  {
    int x,y,d;
    scanf("%lld %lld %lld",&x,&y,&d);
    arr[x]++;
    arr[y]++;
    dist[x][y] = d;
    dist[y][x] = d;
  }

    int p, k;
    scanf("%lld %lld", &p, &k);

  for(int i = 0; i <n;i++)
  {
    for(int j = 0; j < n; j++)
    {
      for(int k = 0; k < n; k++)
      {
        dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
        dist[j][i] = dist[i][j];
      }
      
    }
  }


  int ok = 0;

  for(int i = 0; i < n; i++)
  {
      if(dist[p][i] <= k && arr[i] == 1)
        {
          ok = 1;
          printf("%lld ",i);
        }
  }


  if(ok == 0)
  {
    printf("MEOW");
  }
  return 0; 

}


