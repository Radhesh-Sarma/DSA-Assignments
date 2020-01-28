#include<stdio.h>
#include<stdint.h>
#include<string.h>
#define int long long
  void merge(int arr[],int start,int mid,int end)
  {
    int temp[end-start+1];
    int i = start;
    int j = mid + 1;
    int templen = 0;
    while(i <= mid && j <= end)
    {
      if(arr[i] <= arr[j])temp[templen++] = arr[i++];
      else temp[templen++] = arr[j++];
    }
    while(i <= mid)temp[templen++] = arr[i++];
    while(j <= end)temp[templen++] = arr[j++];
    for(int i = start; i <= end;i++)arr[i] = temp[i-start];
  }
  void mergeSort(int arr[],int start,int end)
  {
    if(start < end)
    {
      int mid = start + (end-start)/2;
      mergeSort(arr,start,mid);
      mergeSort(arr,mid+1,end);
      merge(arr,start,mid,end);
    }
  }
  int32_t main()
  {         
    int n;
    scanf("%lld",&n);
    int arr[n+1];
    for(int i = 1; i <= n; i++)scanf("%lld",&arr[i]);

      mergeSort(arr,1,n);
    int k = n/2;
    if(k%2 == 1)k++;
    int a = 1,ok = 0;
    for(int i = 2; i <= n; i++)
    {
      if(arr[i] == arr[i-1])a++;
      else a = 1;
      if(a >=k)
      {
        ok = 1;
        printf("%lld",arr[i]);
        return 0;
      }
    }
    if(ok == 0)printf("NO MAJORITY ELEMENT");
 return 0;
  }
