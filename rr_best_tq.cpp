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
            else if(arr[i].at == arr[j].at && arr[i].pid > arr[j].pid) {
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
 sort(pList, n);
int low = 1, hi = maxBT;
int tq = -1;
float pre = INT_MAX;
while(low <= hi) {
    timeQuanta = low;
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
}

if(flag)
                ready.push(temp);
}
        float sumWT = 0, sumRT = 0, sumTAT = 0;
        for(int i = 0; i < n; i++) {
            sumWT += ans[i].wt*1.0;
            sumRT += ans[i].rt*1.0;
            sumTAT += ans[i].tat*1.0;
        }
        sumWT = (1.0*sumWT/n);
        low++;
        if(sumWT < pre) {
            tq = timeQuanta;
pre = sumWT; }
    }
    cout<<"\n Optimal Value of Time Quanta : "<<tq;
    cout<<"\n Avg Waiting Time : "<<pre<<endl;
    return 0;
}
