//Author : Radhesh Sarma
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#define int long long
int size = 0;

struct node
{
int data;
struct node* next;
};

void printlist(struct node** head)
{

struct node* temp = (struct node*)malloc(sizeof(struct node));
temp = *head;
	while(temp!=NULL)
	{
	printf("%lld ",temp->data);
	temp = temp->next;
	}
}

void insert(int n,struct node** head)
{
size++;
struct node* newnode = (struct node*)malloc(sizeof(struct node));
newnode->data = n;
newnode->next = NULL;

struct node* temp = *head;

	if(temp == NULL)
	{
		*head = newnode;
	}
	else
	{
		while(temp->next != NULL)temp = temp->next;
		
	temp->next = newnode;
	}

}
int getlast(struct node** head)
{
struct node* temp = *head;


while(temp->next != NULL)temp = temp->next;

return temp->data;

}
int32_t main()
{
	
struct node* head = NULL;


int x;
char ch;

while(1)
{
	scanf("%lld%c",&x,&ch);
	if(size == 0)insert(x,&head);
	else 
	{
	if(x != getlast(&head))insert(x,&head);
	}
	if(ch == '\n')break;
}

printf("%lld\n",size);
printlist(&head);



return 0;
}

