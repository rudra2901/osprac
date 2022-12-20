#include<bits/stdc++.h>
using namespace std;
struct proc{
    int pid,at,bt;
    int remBt;
    int ct,tat,wt,rt;
    bool found;
};
void sort(struct proc arr[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i].at > arr[j].at) {
                struct proc temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
}
            else if(arr[i].at == arr[j].at && arr[i].pid >
arr[j].pid) {
                struct proc temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
} }
} }
int main() {
    int n;
    printf("\n Enter the no of processes: ");
    scanf("%d", &n);
    struct proc pList[n];
    int maxBT = 0;
    queue<proc> ready;
    printf("\n Enter Pid, Arrival Time And Burst Time: \n");
    for(int i=0;i<n;i++) {
        cin>>pList[i].pid>>pList[i].at>>pList[i].bt;
        pList[i].remBt = pList[i].bt;
        pList[i].found = false;
        maxBT = max(maxBT, pList[i].bt);
    }
    int timeQuanta = 0;
 cout<<"\n Enter Time Quanta Size : ";
cin>>timeQuanta;
sort(pList, n);
int tq = -1;
float pre = INT_MAX;
int curr = pList[0].at;
int ind = 0;
for(ind = 0; ind < n; ind++) {
    if(pList[ind].at > curr)
        break;
    ready.push(pList[ind]);
}
vector<proc> ans;
while(!ready.empty() && ans.size() < n) {
    bool flag = false;
    auto temp = ready.front();
    ready.pop();
    while(ind < n) {
        if(pList[ind].at > curr)
            break;
        ready.push(pList[ind]);
ind++; }
    if(!temp.found) {
        temp.rt = curr;
        temp.found = true;
    }
    if(temp.remBt <= timeQuanta) {
        curr += (temp.remBt);
        temp.ct = curr;
        temp.tat = temp.ct-temp.at;
        temp.wt = temp.tat-temp.bt;
        ans.push_back(temp);
} else {
        curr += timeQuanta;
        temp.remBt -= timeQuanta;
        flag = true;
}
    while(ind < n) {
        if(pList[ind].at > curr)
            break;
        ready.push(pList[ind]);
        ind++;
} if(flag)
ready.push(temp);

}
    float sumWT = 0, sumRT = 0, sumTAT = 0;
    for(int i = 0; i < n; i++) {
        printf("\n PID : %d AT : %d BT : %d CT : %d RT : %d WT : %d", ans[i].pid, ans[i].at, ans[i].bt, ans[i].ct, ans[i].rt, ans[i].wt);
        sumWT += ans[i].wt*1.0;
        sumRT += ans[i].rt*1.0;
        sumTAT += ans[i].tat*1.0;
}
    sumWT = (1.0*sumWT/n);
    sumRT = (1.0*sumRT/n);
    sumTAT = (1.0*sumTAT/n);
    cout<<"\n Average WT : "<<sumWT;
    cout<<"\n Average RT : "<<sumRT;
    cout<<"\n Average TAT : "<<sumTAT<<endl;
return 0; }
