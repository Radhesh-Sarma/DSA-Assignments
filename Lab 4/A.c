#include<stdio.h>
#include<stdint.h>
#define int long long
  #define N 1000005
  int ans = 0;
  struct pair
  {
    int p;
    int x;
    int y;
    int d;
    double a;
  };
   int mp,mx,my = 10000000000;
   int absolute(int x,int y)
   {
    if((x-y) < 0)return (y-x);
    return (x-y);
   }
  int manhattan(struct pair pt)
  {
    return absolute(mx,pt.x) + absolute(my,pt.y);
  }
  int compare(struct pair pt1,struct pair pt2)
  {
    if(pt1.a >=0 && pt2.a >=0) 
    {
      return pt1.a <= pt2.a;
    }
    if(pt1.a <=0 && pt2.a <=0) 
    {
      return pt1.a <= pt2.a;
    }
    if(pt1.a >=0 && pt2.a <=0) 
    {
      return 1;
    }
    return 0;

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
    for(int i = 1; i <= n; i++)
    {
      scanf("%lld %lld %lld",&arr[i].p,&arr[i].x,&arr[i].y);
      if(my > arr[i].y)
      {
        mx = arr[i].x;
        my = arr[i].y;
        mp = arr[i].p;
      }
    }


    for(int i = 1; i <= n; i++)
    {
      arr[i].d = manhattan(arr[i]);
      if(arr[i].p != mp)
      { 
        arr[i].a = (double) ((double)(arr[i].y - my)/(double)(arr[i].x - mx));
      } 
      else
      {
        arr[i].a = 100000000;
      }
    }
    mergesort(arr,1,n);
    for(int i = 1; i <= n; i++)
    {
      if(arr[i].p != mp)
      printf("%lld ",arr[i].p);
    }
}
