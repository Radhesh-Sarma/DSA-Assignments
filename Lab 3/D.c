#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#define int long long
#define N 1005
char str[N];
char word[N];
int len1,len2,ans = 0;
int32_t main()
{
	scanf("%s",str);
	scanf("%s",word);
	len1 = strlen(str), len2 = strlen(word);
	for(int i = 0; i <= len1 - len2; i++)
	{
		int ans1 = 0;
		for(int j = 0; j < len2; j++)
		{
			if(str[i + j] != word[j])ans1++;
			if(ans1 > 1)break;
		}
		if(ans1 <= 1)ans++;
	}
	printf("%lld ",ans);
	return 0;
}
