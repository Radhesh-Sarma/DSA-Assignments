#include<stdio.h>
#include<stdint.h>
#define int long long
  #define N 1000005
  int ans = 0;
  int arr[N];
    void merge(int arr[],int start,int mid,int end)
    {
      int temp[end-start+1];
      int i = start,j = mid+1,templen = 0;
      while(i <= mid && j <= end)
      {
        if(arr[i]<=arr[j])temp[templen++] = arr[i++];
        else temp[templen++] = arr[j++];  
      }
      while(i <= mid)temp[templen++] = arr[i++];
      while(j <= end)temp[templen++]= arr[j++];
      for(int i = start; i <= end; i++)arr[i]= temp[i - start]; 
    }
    void mergesort(int arr[],int start,int end)
    {
      if(start < end)
      {
        int mid = (start+end)/2;
        mergesort(arr,start,mid);
        mergesort(arr,mid+1,end);
       merge(arr,start,mid,end);
      }
    }
      int min(int x,int y)
      {
        if(x <= y)return x;
        return y;
      }
      int binarysearch(int low,int high,int x)
      {
        if(x >= arr[high])return x - arr[high];
        if(x <= arr[low]) return arr[low] - x;

        while(low <= high)
        {
          int mid = low + (high - low)/2;
          if(arr[mid] == x)
          {
            return 0;
          }
          if(x < arr[mid+1] && x > arr[mid])
          {
            return min(arr[mid+1]-x,x-arr[mid]);
          }
          if(arr[mid] > x)
          {
            high = mid - 1;
          }
          else 
          {
            low = mid + 1;
          }
        }
        return low;
      }
  int32_t main()
  {         

    int k, n;
    scanf("%lld %lld",&k,&n);

    for(int i = 1; i <= n; i++)
    {
      scanf("%lld",&arr[i]);
    }
    mergesort(arr,1,n);
    int m;
    scanf("%lld",&m);
    while(m--)
    {
      int x;
      scanf("%lld",&x);
      int ans = binarysearch(1,n,x);
      printf("%lld\n",ans);
    }

  return 0;
  }
