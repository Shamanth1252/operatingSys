#include<stdio.h>
typedef struct 
{
  int processId;
  int burstTime;
  int priority;
}Process;
void fcfs(Process processes[],int n){
    int waitingTime=0;
    float totalwaitingTime=0;
    float averageWaitingTime;
    printf("\n FCFS Scheduling algorithm:\n");
    for (int i = 0; i < n; i++)
    {
        printf("process %d is running .\n",processes[i].processId);
        waitingTime+=processes[i].burstTime;
        printf("process %d is finished waiting time :%d\n",processes[i].processId,waitingTime);
        totalwaitingTime+=waitingTime;
    }
    averageWaitingTime=totalwaitingTime/n;
    printf("avg waiting time :%2f\n",averageWaitingTime);
    

}
void sjn(Process processe[],int n)
{
    int totalTime=0;
    int waitingTime=0;
    float totalWaitingTime=0;
    float averageWaitingTime;
    printf("\n SJN scheduling algoorithm :\n");
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(processe[j].burstTime>processe[j+1].burstTime){
                Process temp=processe[j];
                processe[j]=processe[j+1];
                processe[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("process %d is running .\n",processe[i].processId);
        waitingTime+=totalTime;
        totalTime+=processe[i].burstTime;
        printf("process %d finished waiting time:%d\n",processe[i].processId,waitingTime);
        totalWaitingTime+=waitingTime;
    }
    averageWaitingTime=totalWaitingTime /n;
    printf("average waiting time :%2f \n",averageWaitingTime);
    
    
}

void priorityScheduling(Process processes[],int n)
{
    int waitingTime=0;
    float totalWaitingTime=0;
    float averageWaitingTime;

    printf("\n priority scheduling algorithm");

    for (int i = 0; i < n; i++)
    {
    for (int j = 0; j < n-i-1; j++)
    {
       if(processes[j].priority>processes[j+1].priority){
        Process temp=processes[j];
        processes[j]=processes[j+1];
        processes[j+1]=temp;
       }
    }
    }
        for (int i = 0; i < n; i++)
    {
    for (int j = 0; j < n-i-1; j++)
    {
       if(processes[j].priority>processes[j+1].priority){
        Process temp=processes[j];
        processes[j]=processes[j+1];
        processes[j+1]=temp;
       }
    }
    
    }
        for(int i=0;i<n;i++){
        printf("process %d is running .\n",processes[i].processId);
        waitingTime+=totalWaitingTime;
        totalWaitingTime+=processes[i].burstTime;
        printf("process %d finished waiting time:%d\n",processes[i].processId,waitingTime);
        totalWaitingTime+=waitingTime;
 
    }
}
int main(){
    int n;
    printf("enter the number of process");
    scanf("%d",&n);
    Process processes[n];
    for(int i=0;i<n;i++){
        printf("\n enter the details for process %d:\n",i+1);
        processes[i].processId=i+1;
        printf("enter the burst time:");
        scanf("%d",&processes[i].burstTime);
        printf("enter prority:");
        scanf("%d",&processes[i].priority);
    }
    fcfs(processes,n);
    sjn(processes,n);
    priorityScheduling(processes,n);
    return 0;
}
    


