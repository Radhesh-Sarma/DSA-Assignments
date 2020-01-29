#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#define int long long
  #define N 1000005
struct node
{
  int data;
  struct node* next;
};
void printlist(struct node** head)
{
  struct node* temp = *head;
  while(temp != NULL)
  {
    printf("%lld ",temp -> data);
    temp = temp -> next;
  }
  printf("\n");
}
void insert(int n,struct node** head)
{
  struct node* newnode = (struct node*)(malloc(sizeof(struct node)));
  newnode->data = n;
  newnode->next = NULL;
  struct node* temp = *head;
  if(temp == NULL)
  {
    *head = newnode;
  }
  else
  {
    while(temp->next != NULL) temp = temp->next;
    temp->next = newnode;
  }
}

int getlength(struct node** head)
{
  int ans = 0;
  struct node* temp = *head;
  while(temp != NULL)
  {
    ans++;
    temp = temp->next;
  }
  return ans;
}
struct node* pp;

struct node* getmiddle(struct node** head)
{
  struct node* temp = *head;
  int length = getlength(head);
  int middle = length/2;

  if(length%2 == 1)middle++;

  int pos = 0;

  while(temp != NULL)
  {

    if(pos == middle)return temp;
    pos++;
     
     pp = temp;
    temp = temp->next;
  }
  return temp;
}
  
struct node* reverse(struct node** head)
{
  struct node* temp = *head;
  struct node* prev = *head;
  struct node* current = prev->next;
  prev->next = NULL;
  if(current == NULL)
  {
    return *head;
  }
  struct node* ahead = current->next;
  while(current != NULL)
  {
    current->next = prev;
    prev = current;
    current = ahead;
    if(ahead!=NULL)
    {
      ahead = ahead->next;
    }
  *head = prev;
  }
  return *head;
}
  int32_t main()
  {    
    int x;
    char ch;
    struct node* head = NULL;
    while(1)
    {
      scanf("%lld%c",&x,&ch);
      insert(x,&head);
      if(ch == '\n')break;
    }    
   struct node* middle = getmiddle(&head);
    pp->next = NULL;
    struct node* newmiddle = reverse(&middle);
    int len = getlength(&head);
    struct node* temp1 = head;
    struct node* temp2 = newmiddle;
    for(int i = 1; i <= len; i++)
    {
      struct node* temp1next = temp1->next;
      struct node* temp2next = temp2->next;
      temp1->next = temp2;
      temp2->next = temp1next;
      temp1 = temp1next;
      temp2 = temp2next;
      if(temp1 == NULL || temp2 == NULL)break;
    }
    printlist(&head);
}

