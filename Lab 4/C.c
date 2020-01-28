#include<stdio.h>
#include<stdint.h>
#include<string.h>
#define int long long
  #define N 1000005
  int ans = 0;
  int arr[N];
  struct string
  {
    int i;
    char str[55];
  };
  int compare(struct string a1,struct string a2)
  {
    int len1 = strlen(a1.str);
    int len2 = strlen(a2.str);
    if(a1.str[0] != '-' && a2.str[0]!='-')
    {
      if(len1 == len2)
      {
        for(int i = 0 ; i < len1; i++)
        {
          if(a1.str[i]- '0' > a2.str[i] - '0')
          {
            return 0;
          }
          if(a1.str[i]- '0' < a2.str[i] - '0')
          {
            return 1;
          }
        }
        return 1;
      }

      return len1 < len2;
    }
    else if(a1.str[0] == '-' && a2.str[0] == '-')
    {
        if(len1 == len2)
      {
           for(int i = 0 ; i < len1; i++)
        {
          if(a1.str[i]- '0' < a2.str[i] - '0')
          {
            return 0;
          }
          if(a1.str[i]- '0' > a2.str[i] - '0')
          {
            return 1;
          }
        }
        return 1;
      }
      return len1 > len2;
    }
    else if(a1.str[0] == '-')
    {
      return 1;
    }
    else
    {
      return 0;
    }


  }
    void merge(struct string arr[],int start,int mid,int end)
    {
      struct string temp[end-start+1];
      int i = start,j = mid+1,templen = 0;
      while(i <= mid && j <= end)
      {
        if(!compare(arr[i],arr[j]))temp[templen++] = arr[i++];
        else temp[templen++] = arr[j++];  
      }
      while(i <= mid)temp[templen++] = arr[i++];
      while(j <= end)temp[templen++]= arr[j++];
      for(int i = start; i <= end; i++)arr[i]= temp[i - start]; 
    }
    void mergesort(struct string arr[],int start,int end)
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
   scanf("%lld ",&n);
   struct string arr[n+1];
   for(int i = 1; i <= n; i++)
   {
    arr[i].i = i;
    scanf("%s",arr[i].str);
   }
   mergesort(arr,1,n);
    for(int i = 1; i <= n; i++)printf("%s\n",arr[i].str);
   
 return 0;
  }
