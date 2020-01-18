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

void printlist(struct node** head)
{

struct node* temp = *head;

	while(temp != NULL)
	{
		printf("%lld",temp->data);
		temp = temp->next;
	}

printf("\n");
}

void reverseprint(struct node* head)
{

struct node* temp = head;
if(temp == NULL)return;

reverseprint(temp->next);
printf("%lld",temp->data);
}

void insert(int n,struct node** head)
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
	while(temp->next != NULL)temp= temp->next;

	temp->next = newnode;
}

}


char str1[1000005],str2[1000005];

int32_t main()
{
scanf("%s",str1);
scanf("%s",str2);
int len1 = strlen(str1);
int len2 = strlen(str2);


struct node* head1 = NULL;
struct node* head2 = NULL;
struct node* head3 = NULL;


for(int i = len1 - 1; i >= 0; i--)insert(str1[i]-'0',&head1);
for(int i = len2 - 1; i >= 0; i--)insert(str2[i]-'0',&head2);


if(len1 < len2)
{
	while(len1 < len2)
	{
		insert(0,&head1);
		len1++;
	}
}

if(len1 > len2)
{
	while(len1 >  len2)
	{
		insert(0,&head2);
		len2++;
	}
}


struct node* temp1 = head1;
struct node* temp2 = head2;


int c = 0;
while(temp1 != NULL && temp2!= NULL)
{
int x = temp1->data;
int y = temp2->data;

	if(x == 0 && y == 0)
	{
		insert(c,&head3);
		c = 0;
	}
	else if(x == 0 && y == 1)
	{
		if(c == 0)
		{
			insert(1,&head3);
			c = 0;
		}
		else
		{
			insert(0,&head3);	
			c = 1;
		}
		
	}
	else if(x == 1 && y == 0)
	{
		if(c == 0)
		{
			insert(1,&head3);
			c = 0;
		}
		else
		{
			insert(0,&head3);	
			c = 1;
		}
		
	}
	else if(x == 1 && y == 1)
	{
		if(c == 0)
		{
			insert(0,&head3);
			c = 1;
		}
		else
		{
			insert(1,&head3);	
			c = 1;
		}
		
	}

	
	

	temp1= temp1->next;
	temp2 = temp2->next;
}


if(c == 1)insert(c,&head3);
reverseprint(head3);





return 0;
}
