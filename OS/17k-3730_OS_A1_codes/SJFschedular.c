#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
struct proc{
	float bursttime;
	int priority;
};
int main(){
	int num;
	float avgwt,avgburst,avgtat;
	printf("enter no of processes : ");
	scanf("%d",&num);
	
	float *btime=(float*)malloc(num*sizeof(int));
	int *wtime=(int*)malloc(num*sizeof(int));
	int *tat=(int*)malloc(num*sizeof(int));
	int *pri=(int*)malloc(num*sizeof(int));
	int *proc=(int*)malloc(num*sizeof(int));

	printf("Enter burst time and priority of each process : ");
	for(int i=0;i<num;i++){
	printf("\nBurst time of P%d : ",i+1);
	scanf("%f",&btime[i]);
	printf("\npriority of P%d : ",i+1);
	scanf("%d",&pri[i]);
	proc[i]=i+1;
	}
	int pos,temp;
	for(int i=0;i<num;i++){
	pos=i;
	for(int j=i;j<num;j++){
	if(btime[j]<btime[pos]){
		pos=j;}
	}
	temp=btime[i];
	btime[i]=btime[pos];
	btime[pos]=temp;

	temp=pri[i];
	proc[i]=proc[pos];
	proc[pos]=temp;
	}
wtime[0]=0;
int total=0;
for(int i=1;i<num;i++){
	wtime[i]=0;
	for(int j=0;j<i;j++){
		wtime[i]+=btime[j];
	}
total+=wtime[i];
}
avgwt=(float)total/num;
total=0;
printf("\nProcesses\tBurstTime\tWaitingTime\tTurnaroundTime\n");
for(int i=0;i<num;i++){
tat[i]=btime[i]+wtime[i];
total+=tat[i];
printf("\nP%d\t\t%f\t%d\t\t%d \n",proc[i],btime[i],wtime[i],tat[i]);
}
avgtat=(float)total/num;

printf("\nAverage waiting time: %f\nAverage turnaround time : %f ",avgwt,avgtat);
return 0;
}
