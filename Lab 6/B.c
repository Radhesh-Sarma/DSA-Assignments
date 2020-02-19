#include<stdio.h>
#include<stdlib.h>

typedef struct proc{
	int id;
	int start;
	int end;
	struct proc* next;
}proc;

void Merge(proc arr[],int left, int mid, int right){
	int n1 = mid-left+1;
	int n2 = right-mid;
	proc LArr[n1], RArr[n2];
	for (int i = 0; i < n1; i++)
		LArr[i] = arr[left+i];
	for (int i = 0; i < n2; i++)
		RArr[i] = arr[mid+1+i];
	int i = 0, j = 0,k = left;
	while(i < n1 && j < n2)
		if (LArr[i].start < RArr[j].start)
			arr[k++] = LArr[i++];
		else if(LArr[i].start < RArr[j].start)
			arr[k++] = RArr[j++];
		else
			if (LArr[i].id < RArr[j].id)
				arr[k++] = LArr[i++];
			else
				arr[k++] = RArr[j++];

	while (i < n1)
		arr[k++] = LArr[i++];
	while (j < n2)
		arr[k++] = RArr[j++];
}
void MergeSort(proc arr[],int left, int right){
	if (left < right){
		int mid = (left + right)/2;
		MergeSort(arr,left,mid);
		MergeSort(arr,mid+1,right);
		Merge(arr,left,mid,right);
	}
	else return;
}
proc* addArr(proc p){
	proc* new = (proc*)malloc(sizeof(proc));
	*new = p;
	new->next = NULL;
	return new;
}
int main(){
	int n, m,sum = 0,j = 1, time = 0;
	scanf("%d %d",&n,&m);
	proc arr[n];
	for (int i = 0; i < n; i++){
		scanf("%d%d%d",&arr[i].id,&arr[i].start,&arr[i].end);
		arr[i].next = NULL;
	}
	MergeSort(arr,0,n-1);
	proc* qhead = addArr(arr[0]);
	proc* qtail = qhead;
	while(j < n && arr[j].start == 0){
		qtail->next = addArr(arr[j]);
		qtail = qtail->next;
		j+=1;
	}
	proc* trav = qhead;
	while(trav!=NULL){
		if (trav->end > m)
			time+= m;
		else
			time+= trav->end;
		trav->end -= m;
		if (trav->end > 0){
			while(j < n && arr[j].start <= time){
				qtail->next = addArr(arr[j]);
				qtail = qtail->next;
				j+=1;
			}
			qtail->next = addArr(*trav);
			qtail = qtail->next;
		}
		else {
			sum+= time - trav->start;
			trav->end = time;
		}
		trav = trav->next;
	}
	for (int i = 0; i < n; i++)
		sum-=arr[i].end;
	printf("%d\n",sum);
	while(qhead!=NULL){
		printf("%d ", qhead->id);
		qhead = qhead->next;
	}
}