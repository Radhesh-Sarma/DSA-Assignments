#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#define int long long


    int check(int x,int n)
    {
      if(x<= n/x)
      {
        return 1;
      }
      else
      {
        return 0;
      }
    }
    int binarysearch(int n)
    {
      int low = 0, high = n;
      while(low <= high)
      {
        int mid = low + (high - low)/2;
        if(check(mid,n))
        {
          low = mid + 1;
        }
        else 
        {
          high = mid - 1;
        }
      }
      return low - 1;
    }
  int32_t main()
  {         

   
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int queries;
    scanf("%lld",&queries);

    while(queries--)
    {
      int n;
      scanf("%lld",&n);
      int ans = binarysearch(n);
      printf("%lld\n",ans);

    }

    return 0;   
}

