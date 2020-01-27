#include<stdio.h>
#include<stdint.h>
#define int long long
  #define N 1000005
   int arr[N];
  int32_t main()
  {         
    int n, m;
    scanf("%lld %lld",&n,&m);
  for(int i = 1; i <= m; i++)
    {
      int l,r,x;
      scanf("%lld %lld %lld",&l,&r,&x);
      arr[l]+=x;
      arr[r+1]-=x;
    }
    for(int i = 1; i <= n; i++) arr[i] += arr[i-1];
    for(int i = 0; i <= n-1; i++) printf("%lld ",arr[i]);
    return 0; 
}
