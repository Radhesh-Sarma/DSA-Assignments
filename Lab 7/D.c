#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>

#define mod 1000000007
#define int long long
#define N 100000
int heap[N];
int size = 0;

void swap(int * a,int * b)
{
  int t = *a;
  *a = *b;
  *b = t;
}
void max_heapify(int x)
{
  int left = 2*x;
  int right = 2*x+1;
  int largest = x;

  if(left <= size && (heap[left] > heap[largest]))
  {
    largest = left;
  }
  if(right <= size && (heap[right] > heap[largest]))
  {
    largest = right;
  } 

  if(largest != x)
  {
    swap(&heap[x],&heap[largest]);
    max_heapify(largest);
  }
}

void push(int x)
{
  heap[++size] = x;
  for(int i = size; i >= 1 && heap[size/2] < heap[size]; i/=2)
  {
    max_heapify(i/2);
  }
}

void pop()
{
  heap[1] = heap[size--];
  max_heapify(1);
}

int top()
{
  return heap[1];
}
int32_t main()
{ 
  
  heap[0] = 1e18;
  int n, d;
  scanf("%lld %lld",&n , &d);

  for(int i = 1; i <= n; i++)
  {
    int x;
    scanf("%lld",&x);
    push(x);
  }

  int ans = 0;

    while(d--)
    {
      ans = (ans%mod + top()%mod)%mod;
      push(top()/3);
      pop();
    }

  printf("%lld",ans);
  return 0; 
}


