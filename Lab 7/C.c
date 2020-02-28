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

void min_heapify(int x)
{
  int left = 2*x;
  int right = 2*x + 1;
  int smallest = x;

  if(left <= size)
  {
    if(heap[left] < heap[smallest])
    {
      smallest = left;
    }
  }

  if(right <= size)
  {
    if(heap[right] < heap[smallest])
    {
      smallest = right;
    }
  }

  if(smallest != x)
  {
    swap(&heap[smallest],&heap[x]);
    min_heapify(smallest);
  }

}

void push(int x)
{
  heap[++size] = x;

  for(int i = size; i >= 1 && heap[i/2] > heap[i]; i/=2)
  {
    min_heapify(i/2);
  } 
}
void pop()
{
  heap[1] = heap[size--];
  min_heapify(1);
}

int top()
{
  return heap[1];
}
int32_t main()
{ 

  heap[0] = -1e18;
  
  int n;
  scanf("%lld",&n);

  for(int i = 1; i <= n; i++)
  {
    int x;
    scanf("%lld",&x);
    push(x);
  }

  for(int i = 1; i <= n; i++)
  {
    printf("%lld ",top());
    pop();
  }


  return 0; 
}

