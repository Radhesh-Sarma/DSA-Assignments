#include<stdio.h>
#include<stdint.h>
#define int long long
  #define N 1000005
#define f first
#define s second
  int ans = 0;
  struct pair
  {
    int f;
    int s;
  };
  int compare(struct pair x,struct pair y)
  {
    if(x.f == y.f)return x.s < y.f;
    return x.f < y.f;
  }
    void merge(struct pair arr[],int start,int mid,int end)
    {
      struct pair temp[end-start+1];
      int i = start,j = mid+1,templen = 0;
      while(i <= mid && j <= end)
      {
        if(compare(arr[i],arr[j]))temp[templen++] = arr[i++];
        else temp[templen++] = arr[j++];  
      }
      while(i <= mid)temp[templen++] = arr[i++];
      while(j <= end)temp[templen++]= arr[j++];
      for(int i = start; i <= end; i++)arr[i]= temp[i - start]; 
    }
    void mergesort(struct pair arr[],int start,int end)
    {
      if(start < end)
      {
        int mid = (start+end)/2;
        mergesort(arr,start,mid);
        mergesort(arr,mid+1,end);
       merge(arr,start,mid,end);
      }
    }
  int32_t main()
  {         
    int n;
    scanf("%lld",&n);
    struct pair arr[n+1];
    int sum = 0;
    for(int i = 1; i <= n; i++)
      {
        arr[i].s = i;
        scanf("%lld",&arr[i].f);
        sum += arr[i].f;
      } 
      int k;
      scanf("%lld ",&k);
      if(sum <k)
      {
        printf("NO CHANCE");
        return 0;
      }
    mergesort(arr,1,n);
     sum = 0;
    for(int i = 1; i <= n; i++)
    {
      if(sum + arr[i].f >= k)
      {
        printf("%lld \n",arr[i].s );
        return 0;
      }
      printf("%lld \n",arr[i].s);
      sum += arr[i].f;
    }




}
