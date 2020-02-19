#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>

#define int long long
#define N 1005

struct node
{
  int data;
  struct node* next;
};

void push(struct node** head,int x)
{
  struct node* newnode = (struct node*)malloc(sizeof(struct node));
  newnode->data = x;
  newnode->next = *head;
  *head = newnode;
} 

int pop(struct node** head)
{
  if(*head == NULL)
  {
    printf("STACK UNDERFLOW");
    return 1e10;
  } 

  int x = (*head)->data;
  *head = (*head)->next;
  return x;
}

int peek(struct node** head)
{
  if(*head == NULL)
  {
    printf("STACK UNDERFLOW");
    return 1e10;
  }
  return (*head)->data;
}
int32_t main()
{ 


  int queries;
  scanf("%lld",&queries);

  struct node* head = NULL;
  struct node* min = NULL;


  while(queries--)
  {
    char str[10];
    scanf("%s",str);

    if(!strcmp(str,"push"))
    {
          int x;
         scanf("%lld",&x);
         push(&head,x);
         printf("OK pushed %lld\n",x);
         if(min == NULL)
         {
          push(&min,x);
         }
         else if(x <= min->data)
         {
          push(&min,x);
         }
    }
    else if(!strcmp(str,"pop"))
    {
      int x = pop(&head);
      if(x != 1e10)
      {
        printf("OK popped %lld\n",x);
        if(x == min->data)
        {
          pop(&min);
        }
      }
    }
    else if(!strcmp(str,"peek"))
    {
      int x = peek(&head);
      if(x != 1e10)
      {
        printf("%lld\n",x);
      }
    }
    else if(!strcmp(str,"getMin"))
    {
      int x = peek(&min);
      if(x != 1e10)
      {
        printf("%lld\n",x);
      }
    }
  } 
  
  return 0; 
}


