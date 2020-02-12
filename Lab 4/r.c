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


struct node* merge(struct node** h1,struct node** h2)
{
  struct node* temp1 = *h1;
  struct node* temp2 = *h2;
  if(temp1 == NULL)return temp2;
  if(temp2 == NULL)return temp1;

  struct node* h = NULL;
  if(temp1->data <= temp2->data)
  {
    h = temp1;

    h->next = merge(&temp1->next,&temp2);
  }
  else
  {
    h = temp2;
    h->next = merge(&temp1,&temp2->next);
  }
  return h;
}

struct node* mergesort(struct node** head)
{
  struct node* temp = *head;
  if(temp == NULL)return temp;
  if(temp->next == NULL)return temp;

  struct node* slow = temp;
  struct node* fast = temp->next;

  while(fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next;
  }

  struct node* left = *head;
  struct node* right = slow->next;
  slow->next = NULL;

  left = mergesort(&left);
  right = mergesort(&right);
  return merge(&left,&right);
}


  int32_t main()
  {    



}


