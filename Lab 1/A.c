#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#define int long long

int arr[101][101];

int arr2[101][101];
int ans1,ans2;

int32_t main()
{

int n, m;
scanf("%lld %lld",&n,&m);


for(int i = 1; i <= n; i++)
{
   for(int j = 1; j <= m;  j++) 
   {
	scanf("%lld",&arr[i][j]);
   }
}

int p,q;
scanf("%lld %lld",&p,&q);

if(p > n || q > m)
{
printf("NO");
return 0;
}
for(int i = 1; i <= p; i++)
{
     for(int j = 1; j <= q; j++)
     {
	scanf("%lld",&arr2[i][j]);
     }
}

int ok = 0;



for(int i = 1; i <= n; i++)
{
	for(int j = 1; j <= m; j++)
	{
	        int ok1 = 1;
	 	if(m-j+1>=q && n-i+1 >=p)
		{
			for(int xx = 1; xx <= p; xx++)
			{
				for(int yy = 1; yy <= q; yy++)
				{
					if(arr2[xx][yy] != arr[i+xx-1][j+yy-1])
					{
						ok1 = 0;
						break;
					}
				}
				if(ok1 == 0)break;
			}
			if(ok1 == 1)
			{
			 ans1 = i;
			 ans2 = j;
			 ok = 1;
			break;
			}
		}

		if(ok == 1)break;
	}

if(ok == 1)break;
}




if(ok)
{
printf("YES\n");
printf("%lld %lld",ans1-1,ans2-1);
}
else
{
printf("NO");
}





return 0;
}
