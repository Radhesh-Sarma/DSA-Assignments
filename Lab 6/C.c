#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>

#define int long long
#define N 1005


char stack[5000005];
int top = -1;
void push(char ch)
{
  stack[++top] = ch;
}
void pop()
{
  top--;
}
char front()
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
    if(str[i] >= 'a' && str[i] <= 'z')
    {
      printf("%c",str[i]);
    }
    else if(str[i] == ')')
    {
      while(front() != '(')
      {
        printf("%c",front());
        pop();
      }
      pop();
    }
    else
    {
      push(str[i]);
    }
  }



  return 0; 
}


