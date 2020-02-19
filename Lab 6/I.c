#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>

#define int long long
#define N 1005

struct node
{
  char data;
  struct node* left;
  struct node* right;
};

void print(struct node* root)
{
  if(root == NULL)return;
  if(!(root->data >='0' && root->data <= '9'))
  {
    printf("(");
    print(root->left);
    printf("%c",root->data);
    print(root->right);
    printf(")");
  }
  else
  {
    print(root->left);
    printf("%c",root->data);
    print(root->right);
  }
}
int evaluate(struct node* root)
{
  if(root != NULL)
  {
    int res;
    int left = evaluate(root->left);
    int right = evaluate(root->right);

    if(root->data =='+')
    {
      res = left + right;
    }
    else if(root->data =='-')
    {
      res = left - right;
    }
    else if(root->data == '*')
    {
      res = left * right;
    }
    else if(root->data == '/')
    {
      res = left/right;
    }
    else 
    {
      res = root->data - '0';
    }

    return res;
  }
  return 0;

}


int32_t main()
{ 

  struct node* stack[5000];
  char str[5000];

  scanf("%s",str);

  int len = strlen(str);

  int st = -1;

  for(int i = 0; i < len; i++)
  {
    if(str[i] >='0' && str[i] <='9')
    {
      struct node* newnode = (struct node*)malloc(sizeof(struct node));
      newnode->data = str[i];
      newnode->left = NULL;
      newnode->right = NULL;
      stack[++st] = newnode;
    } 
    else
    {
      struct node* newnode = (struct node*)malloc(sizeof(struct node));
      newnode->data = str[i];
      newnode->right = stack[st--];
      newnode->left =stack[st--];
      stack[++st] = newnode;
    }
  }

  struct node* root = stack[0];

  printf("%lld\n",evaluate(root));
  print(root);




  return 0; 
}


