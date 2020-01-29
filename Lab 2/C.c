#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#define int long long
#define N 1000005
struct node
{
	int data;
	struct node* next;
};
void add(int n,struct node** head)
{
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
	    //add at the end
	}
}
void insert(int n, int pos,struct node** head)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = n;
	newnode->next = NULL;
	if(pos == 1)
	{
		newnode->next = *head;
		*head = newnode;
	}
	else
	{	
		struct node* temp = *head;
	    int currentpos = 1;
	    while(currentpos != pos-1)
	    {
	    	currentpos++;
	    	temp = temp->next;
	    }
	    //newnode is inserted between temp and temp->next
	    newnode->next = temp->next;
	    temp->next = newnode;
	}
}
int rem(int n,struct node** head)
{	
	struct node* temp = *head;
	if(temp->data == n)
	{
		*head = temp->next;
	}
	else
	{
		int found = 0;
		struct node* prev;
		while(temp != NULL)
		{
			if(temp->data == n)
			{
				found = 1;
				break;
			}
			prev = temp;
			temp = temp->next;
		}
		if(found == 0)
		{
			return 0;
		}
		prev->next = temp->next;
	}
	 temp = *head;
	struct node* prev;	
	struct node* toberemoved;
	int found = 0;
	while(temp->next != NULL)
	{

		if((temp->next)->data == n)
		{
			found = 1;
			prev = temp;
			toberemoved = temp->next;
		}
		temp = temp->next;
	}
	if(found == 0)
	{
		struct node* temp = *head;
		if(temp->data == n)
		{
			*head = temp->next;
		}
		return 1;
	}
	prev->next = toberemoved->next;
	return 1;
}
int fetch(int x,struct node** head)
{
	struct node* temp = *head;
	int currentpos = 1;
	while(currentpos != x)
	{
		temp = temp->next;
	}
	return temp->data;
}
void reverse(struct node** head)
{
	struct node* temp = *head;
	struct node* prev = *head;
	struct node* current = prev->next;
	prev->next = NULL;
	if(current == NULL)
	{
		return;
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
}
void printlist(struct node** head)
{
	struct node* temp = *head;
	while(temp != NULL)
	{
		printf("%lld ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}
int32_t main()
{
	
	freopen("input.txt","r",stdin);	
       freopen("output.txt","w",stdout);

	struct node* head = NULL;
	 int queries;
	scanf("%lld",&queries);
	while(queries--)
	{
		char str[100];
		scanf("%s",str);
		if(!strcmp(str,"add"))
		{
			int y;
			scanf("%lld",&y);
			add(y,&head);
			printlist(&head);
		}
		else if(!strcmp(str,"insert"))
		{
			int x, y;
			scanf("%lld %lld",&y,&x);
			insert(y,x,&head);
			printlist(&head);
		}
		else if(!strcmp(str,"remove"))
		{
			int y;
			scanf("%lld",&y);
			int k = rem(y,&head);
			if(k == 0)
			{
				printf("Element not found\n");
			}
			else
			{
				printlist(&head);
			}
		}
		else if(!strcmp(str,"reverse"))
		{
			reverse(&head);
			printlist(&head);
		}
		else if(!strcmp(str,"fetch"))
		{	
			int x;
			scanf("%lld",&x);
			int ans = fetch(x,&head);
			printf("%lld\n",ans);
		}	
	}
	return 0;
}
