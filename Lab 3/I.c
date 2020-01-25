#include<stdio.h>
#include<stdint.h>
#define int long long
  int freq[10];
  int32_t main()
  {         
    int n;
    scanf("%lld",&n);
    int ok = 0, sum = 0;
    int arr[n+1];
    for(int i = 1; i <= n; i++)
    {
      scanf("%lld",&arr[i]);
      sum += arr[i];
      if(arr[i] == 0)ok = 1;
      freq[arr[i]]++;
    } 

    if(ok == 0)
    {
      printf("NO NUMBER");
      return 0;
    }
    if(sum%3 == 0)
    {
      for(int i = 9 ; i >= 0; i--)
      {
        int k = freq[i];
        if(n == k && i == 0)
        {
          printf("0");
          return 0;
        }
        while(k--)
        {
          printf("%lld",i);
        }
      }
      return 0;
    }
    int arr1[n+1],arr2[n+1];
    int len1 = 0, len2 = 0;
    for(int i = 0; i <= 9; i++)
    {
      int k = freq[i];
      while(k--)
      {
        if(i%3 == 1)
        {
           arr1[len1++] = i;
        }
        else if(i%3 == 2)
        {
           arr2[len2++] = i;
        }
      }
    }

    if(sum%3 == 1)
    {
      if(len1 >= 1)
      {
        freq[arr1[0]]--;
      }
      else if(len2 >= 2)
      {
        freq[arr2[0]]--;
        freq[arr2[1]]--;
      }
      else
      {

        printf("NO NUMBER");
        return 0;
      }
    }
    else 
    {
      if(len2 >= 1)
      {
        freq[arr2[0]]--;
      }
      else if(len1 >= 2)
      {
        freq[arr1[0]]--;
        freq[arr1[1]]--;
      }
      else
      {

        printf("NO NUMBER");
        return 0;
      }
    }

     for(int i = 9 ; i >= 0; i--)
      {
        int k = freq[i];
        while(k--)
        {
          printf("%lld",i);
        }
      }

    return 0; 
}
