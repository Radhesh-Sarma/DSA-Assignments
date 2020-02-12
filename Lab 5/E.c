#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#define int long long
#define N 10005


void merge(int arr[],int start,int mid,int end)
{
  int i = start;
  int j = mid + 1;

  int temp[end-start+1];
  int templen = 0;

  while(i <= mid && j <= end)
  {
    if(arr[i] <= arr[j])temp[templen++] = arr[i++];
    else temp[templen++] = arr[j++];
  }

  while(i <= mid)temp[templen++] = arr[i++];
  while(j <= end)temp[templen++] = arr[j++];

  for(int i = start; i <= end; i++)
  {
    arr[i] = temp[i-start];
  }

}

void mergesort(int arr[],int start,int end)
{
  if(start < end)
  {
    int mid = start + (end-start)/2;
    mergesort(arr,start,mid);
    mergesort(arr,mid+1,end);
    merge(arr,start,mid,end);
  }
}


int binarysearch(int arr[],int low,int high,int target)
{
 

  while(low <= high)
  {
     int mid = low + (high - low)/2;
    if(arr[mid] >= target)
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



int n,m,l;
scanf("%lld %lld %lld",&n,&m,&l);


int u,v,a,b,k;
scanf("%lld %lld %lld %lld %lld",&u,&v,&a,&b,&k);

int ok1 = 0, ok2 = 0;

int arr[m+1];

for(int i = 1; i <= m; i++)
{
  scanf("%lld",&arr[i]);
  if(arr[i] == u)ok1 = 1;
  if(arr[i] == v)ok2 = 1;
}

int arr2[l+1];

for(int i = 1; i <= l; i++)
{
  scanf("%lld",&arr2[i]);
}


 mergesort(arr,1,m);
 mergesort(arr2,1,l);


for(int i = 1; i <= l; i++)
{
  arr2[i] = a * arr2[i] + b;
}


  if(ok1 == 0 || ok2 == 0)
  {
    printf("NOT POSSIBLE");
    return 0;
  }

  int ans = 0;

  for(int i = 1; i <= m - 1; i++)
  {
    if(arr[i] < u)continue;
    if(arr[i] > v)break;


    int dist = arr[i+1] - arr[i];
    ans += k*((arr2[binarysearch(arr2,1,l,dist)] - b)/a);

    //write condition for not possible 
  }
  printf("%lld",ans);


return 0;
}

