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
struct node* merge(struct node** head1,struct node** head2)
{
  struct node* temp1 = *head1;
  struct node* temp2 = *head2;

  struct node* head = NULL;

  while(temp1!=NULL && temp2!=NULL)
  {
    if(temp1->data <= temp2->data)
      {
        insert(temp1->data,&head);
        temp1 = temp1->next;
      }
      else
      {
        insert(temp2->data,&head);
        temp2 = temp2->next;
      }
  }
  while(temp1!=NULL)
  {
    insert(temp1->data,&head);
    temp1 = temp1->next;
  }
  while(temp2!=NULL)
  {
    insert(temp2->data,&head);
    temp2 = temp2->next;
  }
  return head;
}
void mergesort(struct node** head)
{
  struct node* temp = *head;
  if(temp == NULL || temp->next == NULL)return;

  struct node* temp1 = getmiddle(head);
  pp->next = NULL;
  mergesort(&temp);
  mergesort(&temp1);

  *head = merge(&temp,&temp1);
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
     mergesort(&head);
    printlist(&head);
}


