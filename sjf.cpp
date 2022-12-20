#include<bits/stdc++.h>

using namespace std;

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
} }
} }
struct comp {
    bool operator() (proc const &A, proc const& B) {
        return A.bt > B.bt;
    }
};
int main() {
    int n;
    //printf("enter the no of processes: ");
    scanf("%d", &n);
    struct proc pList[n];
    priority_queue<proc, vector<proc>,  comp> readyQ;
    for(int i=0;i<n;i++) {
        pList[i].pid = i+1;
        scanf("%d %d",  &pList[i].at, &pList[i].bt);
        //readyQ.push(pList[i]);
}
    sort(pList, n);
    vector<proc> ans;
    int curr = 0;
    int ind = 0;
    while(!readyQ.empty() || ans.size() < n) {
        while(pList[ind].at <= curr) {
readyQ.push(pList[ind]);
ind++; }
        proc  temp = readyQ.top();
        readyQ.pop();
        temp.rt = curr;
        curr += temp.bt;
        temp.ct = curr;
        temp.tat = temp.ct-temp.at;
        temp.wt = temp.tat - temp.bt;
        ans.push_back(temp);
    }
    float sumWT = 0, sumRT = 0, sumTAT = 0;
    for(int i = 0; i < n; i++) {
        printf("\n PID : %d AT : %d BT : %d CT : %d RT : %d WT : %d",
ans[i].pid, ans[i].at, ans[i].bt, ans[i].ct, ans[i].rt, ans[i].wt);
        sumWT += ans[i].wt*1.0;
        sumRT += ans[i].rt*1.0;
        sumTAT += ans[i].tat*1.0;
    }
    sumWT = sumWT/(n*1.0);
    sumRT = sumRT/(n*1.0);
    sumTAT = sumTAT/(n*1.0);
    cout<<"\n Average WT = "<<1.0*(sumWT);
    cout<<"\n Average RT = "<<1.0*(sumRT);
    cout<<"\n Average TAT = "<<1.0*(sumTAT)<<"\n";
return 0; }