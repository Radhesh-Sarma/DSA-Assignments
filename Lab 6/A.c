#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>

#define int long long
#define N 1005

char stack[3000005];
int top = -1;

void push(char x)
{
  stack[++top] = x;
}
void pop()
{
  top--;
}
int front()
{
  return stack[top];
}
int size()
{
  return top + 1;
}
int32_t main()
{ 

  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);

  char str[3000005];
  scanf("%s",str);

  int len = strlen(str);

  int i = 0;

  while(i < len)
  {
    if(size() == 0)
    {
        push(str[i]);
        i++;
    }
    else if(str[i] != front())
    {
      push(str[i]);
      i++;
    }
    else
    {
      while(str[i] == front())i++;

      i--;
      while(str[i] == front())pop();
      i++;
    }
  }
  if(size() == 0)
  {
    printf("VANISHED");
  }
  else
  {
    stack[size()] = '\0';
    printf("%s",stack);
  }


  return 0;
}

