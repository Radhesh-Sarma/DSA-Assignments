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

    int arr1[n+1],arr2[n+1];
    int len1 = 1,len2 = 1;
   int k;
    scanf("%lld",&k);
    int j ;
    for(int i = 1; i <= n; i++)
    {
      if(arr[i] == k)
      {
        j = i;
        break;
      }
        arr1[len1++] = arr[i];
    }
    for(int i = j; i <= n; i++)
    {
      arr2[len2++] = arr[i];
    }   
    mergeSort(arr1,1,len1-1);
    mergeSort(arr2,1,len2-1);
    if(arr1[len1-1] < k && arr2[1] == k)
    {
      printf("ALL SET");
      return 0;
    }
   mergeSort(arr,1,n);
   for(int i = 1; i <= n;i++)printf("%lld ",arr[i]);
 return 0;
  }
