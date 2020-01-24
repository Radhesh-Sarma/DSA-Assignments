#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#define int long long
#define N 1000005
int size = 0;
struct node
{
	int data;
	struct node* next;
	struct node* prev;
};
void insert(int n,struct node** head)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = n;
	newnode->next = NULL;
	newnode->prev = NULL;
	struct node* temp = *head;
	if(temp == NULL)
	{
		*head = newnode;
	}
	else
	{
		while(temp->next != NULL)temp = temp->next;
		newnode->prev = temp;
		temp->next = newnode;
	}
}

void printlist(struct node** head)
{
	struct node* temp = *head;

	while(temp != NULL)
	{
		printf("%lld ",temp->data);
		temp = temp->next;
	}
}
int32_t main()
{
	struct node* head1 = NULL;
	struct node* head2 = NULL;
	struct node* head3 = NULL;
	int x;
	char ch;
	while(1)
	{
		scanf("%lld%c",&x,&ch);
		insert(x,&head1);
		if(ch == '\n')break;
	}
	while(1)
	{
		scanf("%lld%c",&x,&ch);
		insert(x,&head2);
		if(ch == '\n')break;
	}
	struct node* temp1 = head1;
	struct node* temp2 = head2;
	while(temp1 != NULL && temp2 != NULL)
	{
		if(temp1->data <= temp2->data)
		{
			insert(temp1->data,&head3);
			temp1 = temp1->next;
		}
		else
		{
			insert(temp2->data,&head3);
			temp2 = temp2->next;
		}
	}
	while(temp1 != NULL)
	{
		insert(temp1->data,&head3);
		temp1 = temp1->next;
	}
	while(temp2 != NULL)
	{
		insert(temp2->data,&head3);
		temp2 = temp2->next;
	}
	printlist(&head3);
	return 0;
}
