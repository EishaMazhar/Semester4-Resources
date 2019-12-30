#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

struct proc{
    float burst_time;
    int priority;
};

int main(){
    int num,i,j; //No of processes
    float avgwt, avg_burstt,avgtat;
    printf("Enter Number of Processes: ");
    scanf("%d",&num);
    
    float *btimes = (float*)malloc(num*sizeof(int));
    int *wtime = (int*)malloc(num*sizeof(int));
    int *procs = (int*)malloc(num*sizeof(int));
    int *tat = (int*)malloc(num*sizeof(int));
    int *priority = (int*)malloc(num*sizeof(int));
   
    printf("Enter Burst Time and Priority for respective processes. (Burst time in seconds) \n");
    for(int i = 0; i < num; i++){
        printf("\nBurst time for Process %d : ", i + 1);
        scanf("%f",&btimes[i]);
        printf("Priorty for Process %d : ", i + 1);
        scanf("%d",&priority[i]);
        procs[i] = i + 1;
    }
    wtime[0] = 0;
    for(int i = 1; i < num; i++){
        wtime[i] = 0;
        for(int j = 0; j < i; j++){
            wtime[i] += btimes[j];
        }
    } 
    printf("\nProcess\tBurstime\tWaiting Time\tTurnaround Time");
    for(int i = 0; i < num; i++){
        tat[i] = btimes[i] +wtime[i];
        avgwt += wtime[i];
        avgtat += tat[i];
        printf("\nP%d\t%f\t\t%d\t\t%d",procs[i],btimes[i],wtime[i],tat[i]);
    }
    avgwt/=num;
    avgtat/=num;
    printf("\n\nAverage Waiting Time : %f\nAverage Turnaround Time : %f\n",avgwt,avgtat);
    return 0;
}
