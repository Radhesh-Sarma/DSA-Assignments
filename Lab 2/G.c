#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define int long long
#define N 5005
int anslow = 0,anshigh = 0;
int len;
char str[N];

int ispalindrome(int low,int high)
{
    while(low <high)
    {
        if(str[low] != str[high])return 0;
        low++;
        high--;
    }
    return 1;
}
int check(int x)
{
    int low=0,high=x-1;
    while(high < len)
    {   
        if(ispalindrome(low,high))
        {
            if(anshigh - anslow < high - low)
            {
                 anshigh=high;
                anslow=low;
            }
            return 1;
        }
        low++;
        high++;
    }
     return 0;
}
    int oddBinarySearch(int low,int high)
    {
    while(low<=high)
    {
        int mid=(low+high)/2;
        int x=2*mid+1;
        if(check(x)){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return low; 
    }

    int evenBinarySearch(int low,int high)
    {
    while(low<=high){
        int mid=(low+high)/2;
        int x=2*mid;
        if(check(x))
        {
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return low; 
    }
int32_t main()
{
        scanf("%s",str);
        len = strlen(str);
        int ans1,ans2;

        if(len%2 == 0)
        {
            ans1 = oddBinarySearch(0,len/2 -1);
            ans2 = evenBinarySearch(0,len/2);
        }
        else
        {
            ans1 = oddBinarySearch(0,len/2);
            ans2 = evenBinarySearch(0,len/2);
        }
        
        printf("%lld\n",anshigh-anslow+1);
        for(int i = anslow; i <= anshigh; i++)
        {
            printf("%c",str[i]);
        }
     return 0;
}

