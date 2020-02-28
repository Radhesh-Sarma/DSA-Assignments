#include<stdio.h>
struct Node{
	int id,arrival,time;
};
typedef struct Node process;
process stack[1000001];
process arr[1000001];
int ans[1000001];
int top=-1,n;
void push(process ele)
{
	stack[++top]=ele;
}
process peek(){
    if(top>-1){
        return stack[top];
    }
}
void pop()
{
	if(top!=-1)
		top--;
}

int main(int argc, char const *argv[])
{
    int n;
    process temp;
    scanf("%d ",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d",&arr[i].id,&arr[i].arrival,&arr[i].time);
    }
    
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1-i; j++)
        {
            if(arr[j].arrival>arr[j+1].arrival){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            else if (arr[j].arrival == arr[j+1].arrival && arr[j+1].id>arr[j].id)
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    int currTime = 0,i = 0;
    do
    {
        while(arr[i].arrival<=currTime && i<n){
            push(arr[i]);
            i++;
        }
        currTime++;
        stack[top].time--;
        if(stack[top].time == 0 && top!=-1){
            ans[stack[top].id]=currTime;
			pop();
        }
    } while (top>-1 || i<n);
    for(i=0;i<1000000;i++)
		if(ans[i]!=0)
			printf("%d %d\n",i,ans[i]);

    return 0;
}
