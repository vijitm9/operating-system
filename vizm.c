#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


struct Node {
	int p_id, pri, b_t, a_t;
	struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;
 
//to create link list with queue

void enq(int x,int y,int z,int a) {
	struct Node* temp = 
		(struct Node*)malloc(sizeof(struct Node));
	temp->p_id =x;
	temp->pri =a;
	temp->a_t=y;
	temp->b_t=z; 
	temp->next = NULL;
	if(front == NULL && rear == NULL){
		front = rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
}


void print() {
	struct Node* temp = front;
	while(temp != NULL) {
		printf("p_id::%d ",temp->p_id);
		printf("pri:: %d ",temp->pri);
			printf("at:: %d ",temp->a_t);
			printf("bt:: %d ",temp->b_t);
		temp = temp->next;
	}
	printf("\n");
}


//to set the priority in order
void setPriority(int at,int bt,int k){
     char temp[5];
  int i,j,pt[10],wt[10],totwt=0,pr[10],temp1,n;
  float avgwt;
 
   n=k;
  for(i=0;i<n;i++)
  {
     
     pt[i] = bt;
     pr[i] = k;
  }
 for(i=0;i<n-1;i++)
 {
 for(j=i+1;j<n;j++)
 {
   if(pr[i]>pr[j])
 {
   temp1=pr[i];
 pr[i]=pr[j];
  pr[j]=temp1;
  temp1=pt[i];
  pt[i]=pt[j];
  pt[j]=temp1;
  }
  }
  }

}

//implement round robin
int rr() 
{ 
 	
	int count,j,n=0,time,remain,flag=0,time_quantum,y=0;
	int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10],tat[20]; 
	struct Node* temp = front;
	while(temp != NULL) 
	{
		bt[n]=temp->b_t;
		at[n]=temp->a_t;
		temp = temp->next;
		rt[n]=bt[n];
		n++;
	}

	remain=n;

  	printf("Enter Quantum Time to be used in this process:\t"); 
  	scanf("%d",&time_quantum); 
  	printf("\n\nProcess\t Turnaround Time Waiting Time\n\n"); 
  	for(time=0,count=0;remain!=0;) 
  { 
  
    if(rt[count]<=time_quantum && rt[count]>0) 
    { 
      time+=rt[count]; 
      rt[count]=0; 
      flag=1; 
    } 
    else if(rt[count]>0) 
    { 
      rt[count]-=time_quantum; 
      time+=time_quantum; 
    } 
    if(rt[count]==0 && flag==1) 
    { 
      remain--; 
      printf("P[%d]\t \t%d\t \t%d\n",count,time-at[count],time-at[count]-bt[count]); 
      wait_time+=time-at[count]-bt[count]; 
      turnaround_time+=time-at[count]; 
      tat[y]=time-at[count];
      y++;
      flag=0; 
    } 
    if(count==n-1) 
      count=0; 
    else if(at[count+1]<=time) 
      count++; 
    else 
      count=0; 
  } 
  printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); 
  printf("Average Turnaround Time = %f\n",turnaround_time*1.0/n); 
  return 0; 
}

int main(){
	
	int i,n,p,at,bt,pp;
	printf("Enter number of processes to execute :");
	scanf("%d",&n);
	for(i=0;i<n;i++){
	
		printf("Enter the Arrival Time for the process :");
				scanf("%d",&at);
				printf("Enter the Burst Time for given process :");
				scanf("%d",&bt);
				printf("Enter Priority of this process :");
				scanf("%d",&pp);
				enq(i,at,bt,pp);
				
			}
			
			rr();
}