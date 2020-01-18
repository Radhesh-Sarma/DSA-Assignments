//Author : Radhesh Sarma
#include<stdio.h>
#include<string.h>
#define N 1000005
char str[N];
int len;
int freq[26];
int anslow,anshigh;

	int check1()
	{
		for(int i = 0; i < 26; i++)
		{
			if(freq[i] > 1)
			{
				return 0;
			}
		}
		return 1;
	}
  int check(int x)
  {
  	for(int i = 0 ; i < 26;i++)
  	{
  		freq[i] = 0;
  	}

  	int low = 0,high = x - 1;

  	for (int i = 0; i < x; i++)
  	{
  		freq[str[i] - 'a']++;
  	}

  	if(check1())
  	{	
  		anslow = 0;
  		anshigh = high;
  		return 1;
  	}


  	while(high +1 < len )
  	{
  		freq[str[low] - 'a']--;
  		low++;
  		high++;
  		freq[str[high]-'a']++;
  		if(check1())
  		{
  			anslow = low;
  			anshigh = high;
  			return 1;
  		}
  	}
    return 0;
  }

  int binarysearch(int low,int high)
  {
    while(low <= high)
    {
      int mid = low + (high - low)/2;
      if(check(mid))
      {
        low = mid + 1;
      }
      else
      {
        high = mid - 1;
      }
    }
    return low - 1;
  }

int main()
{





	   scanf("%s",str);
	   len = strlen(str);
	 	int ans = binarysearch(0,len);
    	printf("%d\n",ans);
    	for(int i = anslow; i <= anshigh; i++)
    	{
    		printf("%c",str[i]);
    	}

    return 0;
}
