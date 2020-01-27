#include<stdio.h>
#include<stdint.h>
#define int long long
  #define N 1000005
  int ans = 0;
    void merge(int arr[],int start,int mid,int end)
    {
      int temp[end-start+1];
      int i = start,j = mid+1,templen = 0;
      while(i <= mid && j <= end)
      {
        if(arr[i] <= arr[j])temp[templen++] = arr[i++];
        else 
        {
          temp[templen++] = arr[j++];
          ans+= mid-i+1;
        }
      }
      while(i <= mid)temp[templen++] = arr[i++];
      while(j <= end)temp[templen++] = arr[j++];
      for(int i = start; i <= end; i++)arr[i] = temp[i - start]; 
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
  int32_t main()
  {         
    int n;
    scanf("%lld",&n);
    int arr[n+1];
    for(int i = 1; i <= n; i++)scanf("%lld",&arr[i]);
    mergesort(arr,1,n);
      printf("%lld",ans);
      return 0;
}
