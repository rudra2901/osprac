#include <stdio.h>
#include<stdio.h>

struct process {
    int WT,AT,BT,TAT,PT;
};

struct process a[10];
void priority() {
    int n,temp[10],t,count=0,short_p;
    float total_WT=0,total_TAT=0,Avg_WT,Avg_TAT;
    printf("Enter the number of the process\n");
    scanf("%d",&n);
    printf("Enter the arrival time , burst time and priority of the process\n");
    printf("ArrivalTime BurstTime PriorityTime\n");
    for(int i=0;i<n;i++) {
        scanf("%d%d%d",&a[i].AT,&a[i].BT,&a[i].PT);
        temp[i]=a[i].BT;
    }
    a[9].PT=10000;
    for(t=0;count!=n;t++) {
        short_p=9;
        for(int i=0;i<n;i++) {
            if(a[short_p].PT>a[i].PT && a[i].AT<=t && a[i].BT>0)
                short_p=i;
        }
        a[short_p].BT=a[short_p].BT-1;
        if(a[short_p].BT==0) {
            count++;
            a[short_p].WT=t+1-a[short_p].AT-temp[short_p];
            a[short_p].TAT=t+1-a[short_p].AT;
            total_WT=total_WT+a[short_p].WT;
            total_TAT=total_TAT+a[short_p].TAT;
} }
    Avg_WT=total_WT/n; Avg_TAT=total_TAT/n;
    printf("PID WaitingTime TurnAroundTime\n");
    for(int i=0;i<n;i++) {
        printf("%d\t %d\t%d\n",i+1,a[i].WT,a[i].TAT);
    }
    printf("Avg waiting time of the process is %f\n",Avg_WT);
    printf("Avg turn around time of the process is %f\n",Avg_TAT);
}
void srtf() {
    int at[10], bt[10], rt[10], endTime, i, smallest;
    int remain = 0, n, time, sum_wait = 0, sum_turnaround = 0;
    printf("Enter no of Processes : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
printf("Enter arrival time for Process P%d : ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter burst time for Process P%d : ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }
    printf("\n\nProcess\t| Arrival Time | Burst Time | Turnaround Time | Waiting Time \n\n");
    rt[9] = 9999;
    for (time = 0; remain != n; time++) {
        smallest = 9;
        for (i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] < rt[smallest] && rt[i] > 0)
                smallest = i;
        }
        rt[smallest]--;
        if (rt[smallest] == 0) {
            remain++;
            endTime = time + 1;
            printf("\nP[%d]\t|\t%d\t|\t%d\t|\t%d\t|\t%d", smallest + 1,
at[smallest], bt[smallest], endTime - at[smallest], endTime -
bt[smallest] - at[smallest]);
            sum_wait += endTime - bt[smallest] - at[smallest];
            sum_turnaround += endTime - at[smallest];
        }
    }
    printf("\n\nAverage waiting time = %f\n", sum_wait * 1.0 / n);
    printf("Average Turnaround time = %f", sum_turnaround * 1.0 / 5);
}
int main() {
    int choice;
    printf("Enter the choice\n");
    printf("1. Priority\n");
    printf("2. SRTF\n");
    scanf("%d",&choice);
    switch(choice) {
        case 1:
priority();
            break;
        case 2:
srtf();
            break;
        default:
            printf("Invalid choice\n");
    return 0;
} }