#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct proc{
    int pid,at,bt;
    int ct,tat,wt,rt;
    bool fin; 
};

void sort(struct proc arr[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i].at > arr[j].at) {
                struct proc temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            else if(arr[i].at == arr[j].at && arr[i].pid > arr[j].pid) {
                struct proc temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            } 
        }
    } 
}

int main() {
    int n;
    printf("enter the no of processes: ");
    scanf("%d", &n);

    struct proc pList[n];
    for(int i=0;i<n;i++) {
        scanf("%d %d", &pList[i].at, &pList[i].bt);
        pList[i].pid = i+1;
    }

    sort(pList, n);
    int curr = 0;
    for(int i = 0; i < n; i++) {
        if(curr < pList[i].at)
            curr = pList[i].at;
        pList[i].rt = curr;
        curr += pList[i].bt;
        pList[i].ct = curr;
        pList[i].tat = pList[i].ct-pList[i].at;
        pList[i].wt = pList[i].tat - pList[i].bt;
    }
    float sumWT = 0, sumRT = 0, sumTAT = 0;
    for(int i = 0; i < n; i++) {
        printf("\n PID : %d AT : %d BT : %d CT : %d RT : %d WT : %d",
        pList[i].pid, pList[i].at, pList[i].bt, pList[i].ct, pList[i].rt,
        pList[i].wt) ;
        sumWT += pList[i].wt*1.0;
        sumRT += pList[i].rt*1.0;
        sumTAT += pList[i].tat*1.0;
    }

    sumWT = sumWT/(n*1.0);
    sumRT = sumRT/(n*1.0);
    sumTAT = sumTAT/(n*1.0);

    printf("\n Average WT = %f", 1.0*(sumWT));
    printf("\n Average RT = %f", 1.0*(sumRT));
    printf("\n Average TAT = %f \n", 1.0*(sumTAT));
    
    return 0; 
}