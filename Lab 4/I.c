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
    if(x.s == y.s) return x.f < y.f;
    return x.s < y.s;
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
    for(int i = 1; i <= n; i++)scanf("%lld %lld",&arr[i].f,&arr[i].s);
    mergesort(arr,1,n);

    int curx = arr[1].f,cury = arr[1].s;

    int ans = 1;
    for(int i = 2; i <= n; i++)
    {
      if(arr[i].f > cury)
      {
        ans++;
        curx = arr[i].f;
        cury = arr[i].s;
      }
    }
    printf("%lld",ans);
}
