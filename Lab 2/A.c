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
	size++;
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
	while(temp!= NULL)
	{
		printf("%lld ",temp->data);
		temp = temp->next;
	}
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

	scanf("%lld %c",&x,&ch);

	 x = (x + size)%size;


	if(ch == 'R')
	{
		int start = (size-x+1)%size;

		int k = 1;

		struct node* temp = head;

		while(temp !=NULL)
		{
			if(k >= start)
			{
				printf("%lld ",temp->data);
			}
			k++;
			temp = temp->next;
		}

		temp = head;
		k = 1;

		while(temp !=NULL)
		{
			if(k < start)
			{
				printf("%lld ",temp->data);
			}
			k++;
			temp = temp->next;
		}
	}
	else
	{

		int start = (x + 1)%size;

		int k = 1;

		struct node* temp = head;

		while(temp !=NULL)
		{
			if(k >= start)
			{
				printf("%lld ",temp->data);
			}
			k++;
			temp = temp->next;
		}

		temp = head;
		k = 1;

		while(temp !=NULL)
		{
			if(k < start)
			{
				printf("%lld ",temp->data);
			}
			k++;
			temp = temp->next;
		}



	}

	return 0;
}
