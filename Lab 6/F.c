#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>

#define int long long
#define N 1005

char stack[5000005];
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

  char str[5000005];
  scanf("%s",str);

  int len = strlen(str);

  for(int i = 0; i < len; i++)
  {
    if(str[i] == '[' || str[i] == '(' || str[i] =='{')
    {
      push(str[i]);
    }
    else if(size() == 0 && (str[i] == ']' || str[i] == ')' || str[i] =='}')) 
    {
      printf("NO");
      return 0;
    }
    else if((str[i] == ']' && front() == '[') || (str[i] == ')' && front() == '(') || (str[i] == '}' && front() == '{'))
    {
      pop();
    }
  }

  if(size() == 0)
  {
    printf("YES");
  }
  else
  {
    printf("NO");
  }
  
  return 0; 
}

