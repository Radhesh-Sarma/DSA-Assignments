//Author : Radhesh Sarma
#include<stdio.h>
#include<string.h>
#define N 1000005
char str[N];
char word[N];
int sentenceLen,wordLen;
int sentenceFreq[26];
int wordFreq[26];
int anslow = -1,anshigh = -1;
	
	  int check1()
	  {
			for(int i = 0; i < 26; i++)
			{
				if(sentenceFreq[i] < wordFreq[i])
				{
					return 0;
				}
			}

			return 1;
	  }

	  int check(int x)
	  {
	  	int low = 0;
	  	int high = x - 1;

	  	for(int i = 0 ; i < 26; i++)
	  	{
	  		sentenceFreq[i] = 0;
	  	}

	  	for(int i = low; i <= high; i++)
	  	{
	  		if(str[i] == ' ')
	  		{
	  			continue;
	  		}
	  		sentenceFreq[str[i] - 'a']++;
	  	}
	  	if(check1())
	  	{
	  		anslow = low;
	  		anshigh = high;
	  		return 1;
	  	}

	  	while(high + 1 < sentenceLen)
	  	{
	  		if(str[low] == ' ')
	  		{
	  			low++;
	  			continue;
	  		}
	  		if(str[high+1] == ' ')
	  		{
	  			high++;
	  			continue;
	  		}

	  		sentenceFreq[str[low] - 'a']--;
	  		low++;
	  		high++;
	  		sentenceFreq[str[high]-'a']++;

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
	        high = mid - 1;
	      }
	      else
	      {
	        low = mid + 1;
	      }
	    }
	    return low;
	  }

int main()
{


	    scanf("%[^\n]%*c", str);
	    scanf("%s",word);
	    sentenceLen = strlen(str);
	    wordLen = strlen(word);

	    if(wordLen > sentenceLen)
	    {
	    	printf("NO WINDOW");
	    	return 0;
	    }
	    for(int i = 0 ; i < 26; i++)
	    {
	    	wordFreq[word[i] - 'a']++;
	    }


	   	int ans = binarysearch(wordLen,sentenceLen);

	   	if(anslow == -1)
	   	{
	    	printf("NO WINDOW");
	    	return 0;
	   	}
	    printf("%d %d\n",anslow,anshigh);

	    for(int i = anslow; i <= anshigh; i++)
	    {
	    	printf("%c",str[i]);
	    }



    return 0;
}
