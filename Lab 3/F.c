#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#include<math.h>
#define int long long
#define MOD 998244353
#define N 100005
int vis[N];
int lvl[N];
int deg[N];
int n;
int min(int a,int b)
{
  if(a <= b) return a;
  return b;
}

struct node{
    int data;
    struct node* next;
};
 
struct list{
    struct node* head;
}*adjlist[N];

void dfs(int node,int level)
{
  if(vis[node])
  {
    return;
  }
  lvl[node] = level;
  vis[node] = 1;
  struct node* temp = adjlist[node]->head;
  while(temp != NULL)
  {
    if(vis[temp->data] == 0)
      {
        dfs(temp->data,level+1);
      }
      temp = temp->next;
  }
}

void addNode(int a, int b)
{
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  temp->next = NULL;
  temp->data = b;
  if(adjlist[a]->head == NULL)
    adjlist[a]->head = temp;
    else
    {
      temp->next = adjlist[a]->head;
      adjlist[a]->head = temp;
    }
}


int32_t main()
{

  scanf("%lld",&n);

    for(int i = 0; i <= N-1; i++)
  {
    adjlist[i] = (struct list*)malloc(sizeof(struct list));
    adjlist[i]->head = NULL;
  }
  for(int i = 1; i <= n-1; i++)
  {
    int x, y;
    scanf("%lld %lld",&x,&y);

    addNode(x,y);
    addNode(y,x);
    deg[x]++;
    deg[y]++;
  }   

  dfs(0,0);

  int ans = 1000000;
  int ans1 = 0;

  for(int i = 0; i <=n-1; i++)
  {
    if(deg[i] == 1)
    {
      ans = min(ans,lvl[i]);
    }
  }

  for(int i = 0; i <= n-1; i++)
  {
  	if(lvl[i] == ans && deg[i] == 1)ans1++;
  }

  printf("%lld\n",ans1);

  for(int i = 0 ; i <= n-1; i++)
  {

    if(deg[i] == 1 && lvl[i] == ans)
    {
      printf("%lld\n",i);
      return 0;
    }
  }

  return 0;
}

