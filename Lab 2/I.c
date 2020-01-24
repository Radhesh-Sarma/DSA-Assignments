#include<stdio.h>
#include<stdint.h>
#include<string.h>
#define int long long
#define N 1000005
char str[N];
char largest[N];
char smallest[N];
char answer[N];
int freq[10];
int len,len1,len2;
int32_t main()
{	
	    scanf("%s",str);
	    len = strlen(str);
	    for(int i = 0 ; i < len; i++)
	    	freq[str[i] - '0']++;
	    int j = 9;
	    while(j>=0)
	    {
	    	int k = freq[j];
	    	while(k >0)
	    	{
	    		largest[len1++] = j + '0';
	    		k--;
	    	}
	    	j--;
	    }
	     j = 0;
	    while(j<=9)
	    {
	    	int k = freq[j];
	    	while(k >0)
	    	{
	    		smallest[len2++] = j + '0';
	    		k--;
	    	}
	    	j++;
	    }
	    if(smallest[0] == '0')
	    {
	    	 j = 1;
	    	while(j <=len2)
	    	{
	    		if(smallest[j] !='0')break;
	    		j++;
	    	}
	    	smallest[0] = smallest[j];
	    	smallest[j] = '0';
	    }
	    int carry = 0;
	    j = 0;
	    for(int i = len-1; i >=0; i--)
	    {
	    	int s = (largest[i]-'0') - (smallest[i] - '0') - carry;
	    	if(s < 0)
	    	{
	    		s+= 10;
	    		carry = 1;
	    	}
	    	else carry = 0;
	    	answer[j++] = s + '0';
	    }
	    int ok = 1;
	    for(int i = len -1 ;i >=0; i--)
	    	{
	    		if(answer[i] !='0' && i > 0)ok = 0;
	    		if(ok && i > 0)continue;
	    		printf("%c",answer[i]);
	    	}
	return 0;
}


