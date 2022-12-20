#include <bits/stdc++.h>

#define FILEIO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

using namespace std;

struct proc{
    int pid,at,bt;
    int remBt;
    int ct,tat,wt,rt;
    bool found;
};

void RR(int timeQuanta, int &curr, int avl, queue<proc> &ready, vector<proc> &ans, int n) {
    int end = curr + avl;
    while(curr < end && !ready.empty() && ans.size() < n) {
        if(end-curr < timeQuanta) {
            bool flag = false;
            auto temp = ready.front();
            ready.pop();

            int tq = end-curr;
            if(!temp.found) {
                temp.rt = curr;
                temp.found = true;
            }

            if(temp.remBt <= tq) {
                curr += (temp.remBt);
                temp.ct = curr;
                temp.tat = temp.ct-temp.at;
                temp.wt = temp.tat-temp.bt;
                ans.push_back(temp);
            } 
            else {
                curr += tq;
                temp.remBt -= tq;
                flag = true;
            }
            if(flag)
                ready.push(temp);
        }
        else {
            bool flag = false;
            auto temp = ready.front();
            ready.pop();
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
            } if(flag)
                ready.push(temp);
        }
    }
}

void FCFS(int &curr, int avl, queue<proc> &ready, vector<proc> &ans, int n) {
    int end = curr + avl;
    while(curr < end) {
        auto temp = ready.front();
        ready.pop();
        if(!temp.found) {
            temp.rt = curr;
            temp.found = true;
        }
        if(temp.remBt > end-curr) {
            int tq = end-curr;
            temp.remBt -= tq;
            // flag = true;
            ready.push(temp);
        } else {
            curr += (temp.remBt);
            temp.ct = curr;
            temp.tat = temp.ct-temp.at;
            temp.wt = temp.tat-temp.bt;
            ans.push_back(temp);
        } 
    }
}

int main() {
//FILEIO
    int n;
    printf("\n Enter the no of processes: ");
    scanf("%d", &n);
    struct proc pList[n];
    int maxBT = 0;
    queue<proc> ready;
    printf("\n Enter Pid And Burst Time: \n");
    for(int i=0;i<n;i++) {
        cin>>pList[i].pid>>pList[i].bt;
        pList[i].at = 0;
        pList[i].remBt = pList[i].bt;
        pList[i].found = false;
        maxBT = max(maxBT, pList[i].bt);
        ready.push(pList[i]);
    }
    int curr = 0;
    vector<proc> ans(n);
    while(!ready.empty() && ans.size() < n) {
       RR(2, curr, 8, ready, ans, n);
       RR(4, curr, 16, ready, ans, n);
       FCFS(curr, 32, ready, ans, n);
    }
    
    float sumWT = 0, sumRT = 0, sumTAT = 0;
    for(int i = 0; i < n; i++) {
        printf("\nPID:%dAT:%dBT:%dCT:%d TAT:%dRT: %d WT : %d", ans[i].pid, ans[i].at, ans[i].bt, ans[i].ct, ans[i].tat,ans[i].rt, ans[i].wt);
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
    
    return 0; 
}
