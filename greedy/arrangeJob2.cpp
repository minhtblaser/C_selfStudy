#include <bits/stdc++.h>

using namespace std;

typedef struct Job{
    int id_job, deadline, profit;
};
bool cmp(Job deadline1, Job deadline2){
    return deadline1.deadline < deadline2.deadline;
}
int main(){
    int a[100] = {0};
    int n;
    cin >> n;
    Job list[n];
    for(int i=0; i<n; i++){
        cin >> list[i].id_job >> list[i].deadline >> list[i].profit;
    }
    sort(list,list+n,comp);
    int count = 0, res = 0;
    for(int i = 0; i <n; i++){
        // find free day to solve deadline 
        while(a[list[i].deadline] && a[i].deadline>0){
            a[i].deadline -= 1;
        }
        if(!a[list[i].deadline] && a[i].deadline > 0){
            a[list[i].deadline] = 1;
            count++;
            res += list[i].profit;
        }
    }
    cout << count << " " << res << endl;
    return 0;
}