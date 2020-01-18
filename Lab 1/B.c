//Author : Radhesh Sarma
#include<stdio.h>  
#define N 1000001

long long composite[N];
long long primes[N];
long long segment[N];
long long n = 0;

  int main() 
  {

      
        long long l,r;
        scanf("%lld %lld",&l,&r);


        //normal seive
        composite[0] = composite[1] = 1;

        for(long long i = 2 ; i * i < N; i++)
        {
        	if(composite[i]) continue;

        	for(long long j = 2*i; j <= N; j+=i)
        	{
        		composite[j] = 1;
        	}
        }

        for(long long i = 0 ; i <= N; i++)
        {
        	if(!composite[i])
        	{
        		primes[n++] = i;
        	}
        }






     		//segmented seive
        for(long long i = 0 ; i <= r-l; i++)
        {
        	segment[i] = 1;
        }


        for(long long i = 0 ; i <= r;i++)
        {
        	long long x = primes[i];
        	if(x*x > r)
        	{
        		break;
        	}
        	long long start =(l/x) * x;

        	if(start < l) start += x;
        	for(long long j = start; j <=r; j+= x)
        	{
        		if(j != x)
        		{
        			segment[j-l] = 0;

        		}
        	} 
        }

        long long arr[10] = {0};
     	for(long long i = l; i <= r; i++)
     	{
     		if(segment[i-l])
     		{
	     	    long long x = i;
	            while (x) 
	            {
	                arr[x % 10]++;
	                x /= 10;
	            }		
     		}
     	}

     	 long long ans = 0;
    long long ans1 = arr[0];
    for (int i = 1; i <= 9; i++) {
        if (arr[i] > ans1) {
            ans1 = arr[i];
            ans = i;
        }
    }
    printf("%lld %lld", ans, ans1);

    return 0;
      }
        



