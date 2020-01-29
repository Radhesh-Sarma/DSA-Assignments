#include <stdio.h>
#include <stdint.h>
#define int long long
  #define INF 100000000000
  #define N 5000005

  int arr[N];

  int brute(int n)
  {
    if(n == 1) return 1;
    else if(n%2 == 0) return 1 + brute(n/2);
    else return 1 + brute(3*n+1);
  }

  int fun(int n)
  {
    if(n == 1)return 1;
    else if(arr[n] != INF)return arr[n];
    else if(n%2 == 0)return arr[n] = 1 + fun(n/2);
    else if(n%2 == 1 && 3*n+1 < N) return arr[n] = 1 + fun(3*n+1);
    return brute(n);
  }

  int32_t main()
  {
    for(int i = 1;i <N; i++)arr[i] = INF;

    arr[1] = 1;
    int n;
    scanf("%lld",&n);
    for(int i = 1; i <= n; i++)
    {
      fun(i);
    }
    int ans1 = 1;
    for(int i = 1; i <= n; i++)
    {
      if(arr[i] >= arr[ans1])
      {
        ans1 = i;
      }
    }
    
    printf("%lld %lld",ans1,arr[ans1]);



    return 0;
}
