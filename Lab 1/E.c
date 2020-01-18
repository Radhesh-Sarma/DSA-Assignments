#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#define int long long

char str[100005];
char ans[100005];
int k = 0;

int32_t main()
{

fgets(str,100005,stdin);

int len = strlen(str) - 1;

str[len++] = ' ';
for(int i = 0 ; i < len; i++)
{

if(str[i] == ' ')
{
	int j = i - 1;
	while(j >= 0)
	{
	if(str[j] == ' ')break;
	ans[k++] = str[j];
	j--;

	}

ans[k++] = ' ';

}

}


printf("%s",ans);
printf("\n");

int ok = 1;
for(int i = 0; i < len; i++)
{

if(str[i] == ' ')
{

	if(ok == 1)
	{
		int j = i - 1;
		while(j >= 0)
		{
		if(str[j] == ' ')break;
		printf("%c",str[j]);
		j--;

		}
		printf("\n");

	}
	
	ok = 1;

}
	if(str[i] != ans[i])
	{
	ok = 0;
	while(str[i] != ' ')i++;

	i--;
	}



}




return 0;
}
